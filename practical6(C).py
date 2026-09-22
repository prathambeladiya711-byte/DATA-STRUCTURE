# Write data into file
f = open("pratham.txt", "w")
f.write("Hello Students\n")
f.write("Welcome to Python")
f.close()

# Append data
f = open("pratham.txt", "a")
f.write("\nThis is additional data")
f.close()

print("Data written and appended successfully")