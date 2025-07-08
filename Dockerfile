# Use GCC image to build and run C++ code
FROM gcc:12

# Create app directory inside container
WORKDIR /app

# Copy all project files
COPY . .

# Compile your C++ code
RUN g++ -std=c++11 shortenurl.cpp -o urlshortener

# Expose the port your app runs on
EXPOSE 8080

# Start the server
CMD ["./urlshortener"]
