import sys
import requests
import subprocess
from PyQt5.QtWidgets import QApplication, QDialog, QFileDialog
from PyQt5.uic import loadUi
from PyQt5.QtGui import QPixmap


class CustomDialog(QDialog):
    def __init__(self):
        super().__init__()
        loadUi("mainwindow.ui", self)
        self.init_ui()

    def init_ui(self):
        self.generate.clicked.connect(self.generate_func)      
        self.save.clicked.connect(self.save_func)

    def generate_func(self):
        image_path = self.image_description.toPlainText()
        self.send_post_request(image_path, 'image.png')
        emoji_image = self.emoji_description.toPlainText()
        self.send_post_request(emoji_image, 'emoji.png')
        pixmap_original = QPixmap('image.png')
        self.original_image.setPixmap(pixmap_original.scaled(550, 630))
        self.run_cpp_binary()
        pixmap_result = QPixmap('output.png')
        self.res_image.setPixmap(pixmap_result.scaled(550, 630))
        self.original_image

   
    def save_func(self):
        pixmap = self.res_image.pixmap()
        if pixmap:
            options = QFileDialog.Options()
            options |= QFileDialog.DontUseNativeDialog 

            file_name, _ = QFileDialog.getSaveFileName(self, "Save Image", "", "Images (*.png *.jpg *.bmp);;All Files (*)", options=options)

            if file_name:
                image = pixmap.toImage()
                if image.save(file_name):
                    print("Image saved successfully.")
                else:
                    print("Failed to save image.")
        else:
            print("No image to save.")


    def send_post_request(self, caption, fileName):
        api_endpoint = 'https://ai.picsart.com/gw1/textToImage/v1/task'
        headers = {
            "accept": "application/json",
            'x-app-authorization' : 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJhaS1oYWNrLWRheSIsImlzcyI6Imh0dHBzOi8vYXV0aG9yaXphdGlvbi1zZXJ2ZXIuY29tIiwiaWF0IjoxNjkwMjc3MTYxfQ.Br8dN1TAlaNi_X32Jlsd9omvv9AdKkcFKDrHECvL_GE',
            "Content-Type": "application/json"
        }

        request_data = {
            "caption": caption,
            "negative_prompt": "over saturation",
            "size": "550x630",
            "model_version": "V14",
            "sampling_method": "Euler A",
            "sampling_steps": 30,
            "count": 6
        }

        response = requests.post(api_endpoint, json=request_data, headers=headers)

        if response.status_code == 200:
            api_response = response.json()

            data_list = api_response.get('data', [])

            if data_list:
                data_item = data_list[0]

                url = data_item.get('url', '')
                image_response = requests.get(url)
                if image_response.status_code == 200:
                    with open(fileName, 'wb') as f:
                        f.write(image_response.content)
                    print(f"Image downloaded successfully for caption: {caption}")
                else:
                    print(f"Failed to download image for caption: {caption}.")
            else:
                print(f"No 'data' field found in the API response or the 'data' list is empty for caption: {caption}.")
                return None
        else:
            print(f"Failed to get a successful response from the API for caption: {caption}.")
            print(f"Error code: {response.status_code}, Response: {response.text}")
            return None
        
   
    def run_cpp_binary(self):
        binary_path = './build/EmojiArt'  
        command_line_arguments = ['image.png', 'emoji.png', '7']  

        try:
            result = subprocess.run([binary_path] + command_line_arguments, capture_output=True, text=True, check=True)
            print("C++ Program Output:")
            print(result.stdout)
        except subprocess.CalledProcessError as e:
            print(f"Error occurred: {e}")
            print("C++ Program Error Output:")
            print(e.stderr)



def main():
    app = QApplication(sys.argv)
    dialog = CustomDialog()
    dialog.show()
    sys.exit(app.exec_())

if __name__ == "__main__":
    main()

