


#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string genre;
    int year;

public:
    Book() : title(""), author(""), genre(""), year(0) {}

    Book(std::string t, std::string a, std::string g, int y) : title(t), author(a), genre(g), year(y) {}

    void setTitle(std::string t) { title = t; }
    void setAuthor(std::string a) { author = a; }
    void setGenre(std::string g) { genre = g; }
    void setYear(int y) { year = y; }

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getGenre() const { return genre; }
    int getYear() const { return year; }

    void printInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Genre: " << genre << std::endl;
        std::cout << "Year: " << year << std::endl;
    }
};

int main() {
    Book myBook("The Great Gatsby", "F. Scott Fitzgerald", "Novel", 1925);

    myBook.printInfo();

    myBook.setTitle("1984");
    myBook.setAuthor("George Orwell");
    myBook.setGenre("Dystopian");
    myBook.setYear(1949);

    myBook.printInfo();

    return 0;
}







#include <iostream>
#include <vector>
#include <stdexcept>

class Vector {
private:
    std::vector<double> data;

public:
    Vector(const std::vector<double>& vec) : data(vec) {}

    Vector add(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        std::vector<double> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result[i] = data[i] + other.data[i];
        }
        return Vector(result);
    }

    Vector subtract(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        std::vector<double> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result[i] = data[i] - other.data[i];
        }
        return Vector(result);
    }

    Vector multiply(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        std::vector<double> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result[i] = data[i] * other.data[i];
        }
        return Vector(result);
    }

    double dotProduct(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        double result = 0;
        for (size_t i = 0; i < data.size(); ++i) {
            result += data[i] * other.data[i];
        }
        return result;
    }

    void print() const {
        for (double val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector vec1({ 1.0, 2.0, 3.0 });
    Vector vec2({ 4.0, 5.0, 6.0 });

    Vector sum = vec1.add(vec2);
    std::cout << "Sum: ";
    sum.print();

    Vector difference = vec1.subtract(vec2);
    std::cout << "Difference: ";
    difference.print();

    Vector product = vec1.multiply(vec2);
    std::cout << "Product: ";
    product.print();

    double dot = vec1.dotProduct(vec2);
    std::cout << "Dot Product: " << dot << std::endl;

    return 0;
}





#include <iostream>
#include <string>

class File {
protected:
    std::string name;
    double size;

public:
    File(const std::string& name, double size) : name(name), size(size) {}

    std::string getName() const { return name; }
    double getSize() const { return size; }

    virtual void printInfo() const {
        std::cout << "Name: " << name << ", Size: " << size << " MB" << std::endl;
    }
};

class TextFile : public File {
private:
    std::string content;

public:
    TextFile(const std::string& name, double size, const std::string& content)
        : File(name, size), content(content) {}

    std::string read() const { return content; }
    void write(const std::string& newContent) { content = newContent; }

    void printInfo() const override {
        File::printInfo();
        std::cout << "Content: " << content << std::endl;
    }
};

class Image : public File {
private:
    std::string resolution;

public:
    Image(const std::string& name, double size, const std::string& resolution)
        : File(name, size), resolution(resolution) {}

    std::string getResolution() const { return resolution; }

    void printInfo() const override {
        File::printInfo();
        std::cout << "Resolution: " << resolution << std::endl;
    }
};

class Video : public File {
private:
    double duration;

public:
    Video(const std::string& name, double size, double duration)
        : File(name, size), duration(duration) {}

    double getDuration() const { return duration; }

    void printInfo() const override {
        File::printInfo();
        std::cout << "Duration: " << duration << " minutes" << std::endl;
    }
};

int main() {
    TextFile txtFile("example.txt", 0.5, "This is an example text.");
    Image imgFile("image.jpg", 2.3, "1920x1080");
    Video vidFile("video.mp4", 500.0, 120.0);

    txtFile.printInfo();
    imgFile.printInfo();
    vidFile.printInfo();

    std::cout << "Reading text file content: " << txtFile.read() << std::endl;
    txtFile.write("Updated text content.");
    std::cout << "Updated text file content: " << txtFile.read() << std::endl;

    return 0;
}





#include <iostream>
#include <string>

class ElectronicDevice {
protected:
    std::string name;
    double screenSize; 

public:
    ElectronicDevice(const std::string& name, double screenSize)
        : name(name), screenSize(screenSize) {}

    virtual void setOperatingSystem(const std::string& os) = 0;

    virtual void printInfo() const {
        std::cout << "Name: " << name << ", Screen Size: " << screenSize << " inches" << std::endl;
    }
};

class Smartphone : public ElectronicDevice {
private:
    std::string operatingSystem;

public:
    Smartphone(const std::string& name, double screenSize)
        : ElectronicDevice(name, screenSize) {}

    void setOperatingSystem(const std::string& os) override {
        operatingSystem = os;
    }

    void printInfo() const override {
        ElectronicDevice::printInfo();
        std::cout << "Operating System: " << operatingSystem << std::endl;
    }
};

class Tablet : public ElectronicDevice {
private:
    std::string operatingSystem;

public:
    Tablet(const std::string& name, double screenSize)
        : ElectronicDevice(name, screenSize) {}

    void setOperatingSystem(const std::string& os) override {
        operatingSystem = os;
    }

    void printInfo() const override {
        ElectronicDevice::printInfo();
        std::cout << "Operating System: " << operatingSystem << std::endl;
    }
};

class Laptop : public ElectronicDevice {
private:
    std::string operatingSystem;

public:
    Laptop(const std::string& name, double screenSize)
        : ElectronicDevice(name, screenSize) {}

    void setOperatingSystem(const std::string& os) override {
        operatingSystem = os;
    }

    void printInfo() const override {
        ElectronicDevice::printInfo();
        std::cout << "Operating System: " << operatingSystem << std::endl;
    }
};

int main() {
    Smartphone phone("iPhone", 6.1);
    Tablet tablet("iPad", 10.2);
    Laptop laptop("MacBook", 13.3);

    phone.setOperatingSystem("iOS");
    tablet.setOperatingSystem("iPadOS");
    laptop.setOperatingSystem("macOS");

    phone.printInfo();
    tablet.printInfo();
    laptop.printInfo();

    return 0;
}

