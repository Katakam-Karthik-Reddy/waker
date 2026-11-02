# Configure the project with the cross-compilation toolchain
./setup_env.ps1

cmake -S . -B build

# Clean and Build the project
cmake --build build --clean-first --verbose

# to flash the target ( this use the target from CMakeList.txt)
cmake --build build --target flash