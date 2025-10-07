# Start from a base image that has the g++ compiler and Git
FROM gcc:latest

# Install Google Test inside the container
# This ensures our build environment is consistent
RUN apt-get update && apt-get install -y libgtest-dev cmake \
    && cd /usr/src/gtest \
    && cmake CMakeLists.txt \
    && make \
    && cp lib/*.a /usr/lib

# Set the working directory inside the container
WORKDIR /app

# Copy all our project files into the container's /app directory
COPY . .

# Run the 'make' command to compile our application inside the container
RUN make

# This is the command that will run when the container starts
CMD ["./scientific_calculator"]