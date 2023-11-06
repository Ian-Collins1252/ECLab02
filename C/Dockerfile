# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY sales.cpp .
# Compile the C program
RUN gcc -o SalesReport sales.cpp
# Set the command to run when the container starts
CMD ["./SalesReport"]