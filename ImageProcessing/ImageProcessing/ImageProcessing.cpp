#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/core/utils/logger.hpp>

using namespace std;
using namespace cv;

static string loadImage() {
    cout << "Enter the path of the Image: ";
    string newPath;
    cin.ignore();
    getline(cin, newPath);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- Invalid Choice ----" << endl;
        return "";
    }

    Mat img = imread(newPath);

    if (img.empty()) {
        cout << "Image Not Found" << endl;
        return "";
    }

    return newPath;
}

void static imageBlur(Mat& img) {
    int blur = -1;
    cout << "Enter how much blur you want (Only ODD numbers (1 - 19)): ";
    cin >> blur;

    if (cin.fail() || !(blur & 1) || blur < 1 || blur > 19) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- Invalid Choice ----" << endl;
        return;
    }

    GaussianBlur(img, img, Size(blur, blur), 0, 0);
    cout << "Image Blurred" << endl;
}

void static sharpImage(Mat& img) {
    Mat imgBlur;
    GaussianBlur(img, imgBlur, Size(1, 1), 0, 0);
    addWeighted(img, 2.5, imgBlur, -1.5, 0, img);
    cout << "Image Sharpened" << endl;
}

void static brightImage(Mat& img) {
    int bright = -1;
    cout << "Enter how much Brightness you want (-100 to 100): ";
    cin >> bright;

    if (cin.fail() || bright < -100 || bright > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- Invalid Choice ----" << endl;
        return;
    }

    img.convertTo(img, -1, 1, bright);
    cout << "Image Brightness Changed" << endl;
}

void static contrastImage(Mat& img) {
    double contrast = -1;
    cout << "Enter how much Contrast you want (0 to 2): ";
    cin >> contrast;

    if (cin.fail() || contrast < 0 || contrast > 2) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- Invalid Choice ----" << endl;
        return;
    }

    img.convertTo(img, -1, contrast, 0);
    cout << "Image Contrast Changed" << endl;
}

void static saveImage(const Mat& img) {
    cout << "Enter the path to save the Image (including filename and extension): ";
    string savePath;
    cin >> savePath;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- Invalid Choice ----" << endl;
        return;
    }

    bool success = imwrite(savePath, img);
    if (success) {
        cout << "Image saved successfully at " << savePath << endl;
    }
    else {
        cout << "Failed to save the image. Please check the path and try again." << endl;
    }
}

Mat static resizeImage(const Mat& img) {
    cout << "The Current Size of the Image is: " << img.size() << endl;

    int width = img.size().width;
    int height = img.size().height;

    cout << "Enter the new Width of the Image: ";
    cin >> width;

    if (cin.fail() || width <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- Invalid Choice ----" << endl;
        return img; 
    }

    cout << "Enter the new Height of the Image: ";
    cin >> height;

    if (cin.fail() || height <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- Invalid Choice ----" << endl;
        return img; 
    }

    Mat resizedImage;
    resize(img, resizedImage, Size(width, height));
    cout << "Image Resized" << endl;

    return resizedImage;
}

Mat static cropImage(const Mat& img) {
    cout << "The Current Size of the Image is: " << img.size() << endl;

    int width = 0;
    int height = 0;
    int startX = 0;
    int startY = 0;

    cout << "Enter the starting X-Coordinate of new Image : ";
    cin >> startX;

    if (cin.fail() || startX < 0 || startX > img.size().width) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- Invalid Choice ----" << endl;
        return img;
    }

    cout << "Enter the starting Y-Coordinate of new Image : ";
    cin >> startY;

    if (cin.fail() || startY < 0 || startY > img.size().height) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- Invalid Choice ----" << endl;
        return img;
    }

    cout << "Enter the new Width of the Image: ";
    cin >> width;

    if (cin.fail() || width <= 0 || width > img.size().width) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- Invalid Choice ----" << endl;
        return img;
    }

    cout << "Enter the new Height of the Image: ";
    cin >> height;

    if (cin.fail() || height <= 0 || height > img.size().height) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- Invalid Choice ----" << endl;
        return img;
    }

    Rect roi(startX, startY, width, height);
    Mat croppedImage;

    croppedImage = img(roi);

    cout << "Image Cropped" << endl;

    return croppedImage;
}

void static colorMap(Mat& img) {
    cout << "-----------------------------" << endl;
    cout << "Color Mapping" << endl;
    cout << "1. Autumn" << endl;
    cout << "2. Bone" << endl;
    cout << "3. Cool" << endl;
    cout << "4. DeepGreen" << endl;
    cout << "5. Winter" << endl;
    cout << "-----------------------------" << endl;

    int choice = -1;
    cout << "Your Choice : ";
    cin >> choice;

    switch (choice) {
    case 1:
        applyColorMap(img, img, COLORMAP_AUTUMN);
        cout << "Color Map Applied" << endl;
        break;
    case 2:
        applyColorMap(img, img, COLORMAP_BONE);
        cout << "Color Map Applied" << endl;
        break;
    case 3:
        applyColorMap(img, img, COLORMAP_COOL);
        cout << "Color Map Applied" << endl;
        break;
    case 4:
        applyColorMap(img, img, COLORMAP_DEEPGREEN);
        cout << "Color Map Applied" << endl;
        break;
    case 5:
        applyColorMap(img, img, COLORMAP_WINTER);
        cout << "Color Map Applied" << endl;
        break;
    default:
        cout << endl << "---- Invalid Choice ----" << endl;
        break;
    }
}

int main() {
    cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);

    string path = "";
    Mat img;
    int choice = -1;

    do {
        cout << "------------------------------------------------" << endl;
        cout << "1. Load an Image" << endl;
        cout << "2. Display Image" << endl;
        cout << "3. Grayscale the Image" << endl;
        cout << "4. Blur the Image" << endl;
        cout << "5. Sharpen the Image" << endl;
        cout << "6. Change the Brightness of the Image" << endl;
        cout << "7. Change the Contrast of the Image" << endl;
        cout << "8. Resize Image" << endl;
        cout << "9. Crop Image" << endl;
        cout << "10. Apply Color Map" << endl;
        cout << "11. Save the Image" << endl;
        cout << "12. End the Application" << endl;
        cout << "------------------------------------------------" << endl;

        cout << endl << "Enter Your Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "---- Invalid Choice ----" << endl;
            continue;
        }

        switch (choice) {
        case 1:
            path = loadImage();
            if (!path.empty()) {
                img = imread(path);
                cout << "Image Loaded" << endl;
            }
            break;
        case 2:
            if (!img.empty()) {
                imshow("Display Image", img);
                waitKey(0);
                destroyWindow("Display Image");
            }
            else {
                cout << "No image loaded. Please load an image first." << endl;
            }
            break;
        case 3:
            if (!img.empty()) {
                cvtColor(img, img, COLOR_BGR2GRAY);
                cout << "Image Grayscaled" << endl;
            }
            else {
                cout << "No image loaded. Please load an image first." << endl;
            }
            break;
        case 4:
            if (!img.empty()) {
                imageBlur(img);
            }
            else {
                cout << "No image loaded. Please load an image first." << endl;
            }
            break;
        case 5:
            if (!img.empty()) {
                sharpImage(img);
            }
            else {
                cout << "No image loaded. Please load an image first." << endl;
            }
            break;
        case 6:
            if (!img.empty()) {
                brightImage(img);
            }
            else {
                cout << "No image loaded. Please load an image first." << endl;
            }
            break;
        case 7:
            if (!img.empty()) {
                contrastImage(img);
            }
            else {
                cout << "No image loaded. Please load an image first." << endl;
            }
            break;
        case 8:
            if (!img.empty()) {
                img = resizeImage(img);
            }
            else {
                cout << "No image loaded. Please load an image first." << endl;
            }
            break;
        case 9:
            if (!img.empty()) {
                img = cropImage(img);
            }
            else {
                cout << "No image loaded. Please load an image first." << endl;
            }
            break;
        case 10:
            if (!img.empty()) {
                colorMap(img);
            }
            else {
                cout << "No image loaded. Please load an image first." << endl;
            }
            break;
        case 11:
            if (!img.empty()) {
                saveImage(img);
            }
            else {
                cout << "No image loaded. Please load an image first." << endl;
            }
            break;
        case 12:
            cout << "Ending the application." << endl;
            break;
        default:
            cout << endl << "---- Invalid Choice ----" << endl;
            break;
        }

    } while (choice != 12);

    return 0;
}