#include <iostream>
#include <vector>

class Image {
public:
    int width, height;

    Image(int w, int h) : width(w), height(h) {}
};

class Url {
public:
    std::string link;

    Url(const std::string& url) : link(url) {}
};

class Account {
public:
    std::string username;
    
    Account(const std::string& name) : username(name) {}
};

class ImageStorage { //статические методы и поля класса
public:
    static void Save(const Image& image, const std::string& path) {
        std::cout << "[ImageStorage] Saving image to: " << path << std::endl;
    }

    static int DeleteDuplicates() {
        std::cout << "[ImageStorage] Deleting duplicate images..." << std::endl;
        return 3; 
    }
};

class ImageProcessor {
public:
    static Image Resize(const Image& image, int height, int width) {
        std::cout << "[ImageProcessor] Resizing image to " << width << "x" << height << std::endl;
        return Image(width, height);
    }

    static Image InvertColors(const Image& image) {
        std::cout << "[ImageProcessor] Inverting colors of image...\n";
        return image;
    }
};

class ImageDownloader {
public:
    static Image Download(const Url& imageUrl) {
        std::cout << "[ImageDownloader] Downloading image from: " << imageUrl.link << "\n";
        return Image(400, 800);  
    }
};

class AccountService {
public:
    static void SetImageAsAccountPicture(const Image& image, const Account& account) {
        std::cout << "[AccountService] Setting profile picture for " << account.username << std::endl;
    }
};

int main() {

    Url imageUrl("https://www.pinterest.com/image.jpg");
    Image downloadedImage = ImageDownloader::Download(imageUrl); 

    Image resizedImage = ImageProcessor::Resize(downloadedImage, 500, 500);
    Image invertedImage = ImageProcessor::InvertColors(resizedImage);

    ImageStorage::Save(invertedImage, "/etc/home/user/pictures/image.jpg");

    std::cout << ImageStorage::DeleteDuplicates() << " duplicate images remove." << std::endl;

    Account user("Luffy");
    AccountService::SetImageAsAccountPicture(invertedImage, user);

    return 0;
}
