## Image-to-Emojoi Pixel Art Generator

# Description

The Picsart Text-to-Image Pixel Art Generator is a desktop application that allows users to generate pixel art representations of images and emojis from given descriptions using the Picsart text-to-image API.  The application is built on a combination of C++, Python, and Qt framework. The main logic is implemented in C++, and the user interface is designed using Qt framework, providing an intuitive and user-friendly experience.


# Features

Generate images and emojis from descriptions using the Picsart text-to-image API.
Analyze the colors and patterns of the generated images to replace certain regions with suitable emoji characters, creating a pixel art representation.
User-friendly interface to select the folder for saving the generated pixel art image.
Save the final pixel art representation as an image file.


# Requirements

Before running the Picsart Text-to-Image Pixel Art Generator, ensure you have the following dependencies installed:

- `CMake (Version 3.0 or higher)`
- `Python (Version 3)`
- `C++ compiler (GCC)`
- `Qt framework (Version 5)`

# Setup

1. Navigate to the project directory:

    - `cd Image2Emoji`

2. Compile the C++ code using CMake.

    - `cd build`
    - `cmake ..`
    - `make`
    - `cd ..`

3. After successful compilation, the executable for the application should be available in the "build" directory.

# Usage

Run the Python script to start the Image-to-Emoji Pixel Art Generator:
    - `python3 main.py`



1. The application will prompt you to enter a description for the image or emoji you want to generate. Provide the description and proceed.

2. The C++ program will use the Picsart text-to-image API to generate the image from the given description.

3. The generated image will be analyzed for colors and patterns to create a pixel art representation using suitable emoji characters.

4. The pixel art representation will be displayed in the Python application.

5. Choose the folder where you want to save the generated pixel art image by following the on-screen instructions.

6. Save the pixel art representation as an image file in the selected folder.


# Troubleshooting

- If you encounter any issues during the compilation process or while running the application, ensure that you have all the required dependencies installed correctly.

- If you face any problems with the Picsart text-to-image API, check the API documentation and verify the API key (if required).

- For any interface-related issues, ensure that you have Qt framework installed and configured properly.
