cmake_minimum_required(VERSION 3.16) # Specify the minimum required version
project(XXProductLineProject) # Replace with your project's name

# Enable ordered processing of subdirectories (similar to CONFIG = ordered in qmake)
add_subdirectory(SharedAssets)
add_subdirectory(UniqueAsset1)
add_subdirectory(UniqueAsset2)
add_subdirectory(UniqueAsset3)
add_subdirectory(UniqueAsset4)
add_subdirectory(XXProductLineApplication)
# add_subdirectory(XXProductLineTests)
