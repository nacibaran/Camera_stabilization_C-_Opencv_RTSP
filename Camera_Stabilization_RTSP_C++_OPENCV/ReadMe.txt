Mail naci.baran1903@gmail.com
Instagram naci.baran
linkedin nacibaran


// Selamlarr.

Türkçe:


Program, OpenCV'deki VideoCapture sınıfını kullanarak bir RTSP akışı açar.
Son buffer_size kareyi içeren bir önbellek oluşturur.
Lucas-Kanade yöntemini kullanarak önbellekteki ilk ve son kareler arasındaki hareket vektörlerini hesaplar.
Hareket vektörlerini kullanarak homografi matrisini tahmin ederek video karelerini stabilize eder.
Tahmin edilen homografi matrisini son kareden elde edilen stabilize edilmiş bir kareye uygular.
Stabilize edilmiş kareyi imshow fonksiyonu kullanarak gösterir.

// İzlenecek adımlar.

OpenCV'yi bilgisayarınıza yükleyin. Eğer henüz yüklemediyseniz OpenCV'yi resmi web sitesinden indirebilirsiniz: https://opencv.org/releases/
Kodu tercih ettiğiniz bir IDE veya metin editörüne kopyalayın.
RTSP URL'sindeki <username>, <password>, <ip_address> ve <port> yerlerini gerçek RTSP akışınıza ait kimlik bilgileriyle değiştirin.
Kodu derleyin ve çalıştırın.


// Hi every onee.

English:

The program opens an RTSP stream using the VideoCapture class from OpenCV.
It creates a buffer of the last buffer_size frames.
It calculates optical flow vectors between the first and last frames in the buffer using the Lucas-Kanade method.
It estimates a homography matrix using the optical flow vectors to stabilize the video frames.
It applies the estimated homography matrix to the last frame in the buffer to obtain a stabilized frame.
It displays the stabilized frame using the imshow function.


Steps:

Install OpenCV on your computer if you haven't already. You can download OpenCV from the official website: https://opencv.org/releases/
Copy the code into a new C++ project in your preferred IDE or text editor.
Replace <username>, <password>, <ip_address> and <port> in the RTSP URL with your actual RTSP stream credentials.
Build and run the code.


