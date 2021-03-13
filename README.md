# Vulkan-Windows
This repository contains code examples for Vulkan Library. 
This is the tutorial that we are following: https://vulkan-tutorial.com/Introduction

## Setup Environment

It is required to configure your environment and install Vulkan SDK in oder to run these examples.
Follow the steps below to setup your working environment correctly:

1. Download Vulkan SDK: https://vulkan.lunarg.com/sdk/home
2. Install the Vulkan SDK in your ```C:``` bacause the project will look there for the SDK
3. Verify that your graphics card and driver properly support Vulkan. 
    - Go to the directory where you installed the SDK
    - Open the Bin directory 
    - Run the vkcube.exe demo. You should see the following:
    ![Image of demo window](https://github.com/DrRixxo/Vulkan-Windows/blob/master/Readme/images/cube_demo.png)


    If you receive an error message then ensure that your drivers are up-to-date, include the Vulkan runtime and that your graphics card is supported.
4. Download GLFW library: https://www.glfw.org/download.html we'll use the GLFW library to create a window, which supports Windows, Linux and MacOS. You can download the **64-bit Windows Binary** and extract into a folder.
5. Vulkan does not include a library for linear algebra operations, so we'll have to download GLM Library: https://github.com/g-truc/glm/releases extract into a folder.
6. Now we need to add the envirnment variables to point to the extracted libraries. Go to ```Control Panel``` -> ```System and Security``` -> ```System``` -> ```Advanced system Settings``` in the ```Advanced``` tab click ```Environment Variables...```.

![Image of Environment Variables settings window](https://github.com/Rixxo/Vulkan-Windows/blob/master/Readme/images/env_vars.PNG)

7. In the ```User variables for <username>``` click ```New...``` and add the following envirnment variables:

![Image of `User variables settings window](https://github.com/Rixxo/Vulkan-Windows/blob/master/Readme/images/user_vars.PNG)

8. Add `GLFW_PATH` variable, this should point to the `glfw-3.3.2.bin.WIN64` which should be the folder where you have extracted the library:

![Add GLFW_PATH variable](https://github.com/Rixxo/Vulkan-Windows/blob/master/Readme/images/glfw_env_var.PNG)

9. Add `GLM_PATH` varable, this should point to the `glm` which should be the folder where you have extracted the library:

![Add GLM_PATH variable](https://github.com/Rixxo/Vulkan-Windows/blob/master/Readme/images/glm_env_var.PNG)

