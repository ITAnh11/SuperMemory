# SuperMemory

* Mục tiêu của game : Rèn luyện trí nhớ 
* Thể loại: Game ngắn, đơn giản (Casual)
* Chơi trên máy tính
* Cách thức chơi
  - Đầu tiên, màn hình sẽ xuất hiện các nhân vật di chuyển theo 2 hướng trái phải, mục tiêu người chơi phải ghi nhớ hình ảnh nhân vật, thứ tự và hướng di chuyển.
  - Sau khi màn hình sẽ chuyển cảnh, sẽ xuất hiện ngẫu nhiên nhân vật di chuyển, dựa vào trí nhớ người chơi sẽ phải lựa chọn đúng  
  - Chọn sai sẽ chơi lại, do tạo ngẫu nhiên nên mỗi lần chơi lại sẽ khác nhau
  - Chọn đúng hết tăng level (tăng số lượng nhân vật)


## Development Process

* 1.0 Hello Game  
	- 1.1 Tạo cửa sổ, load ảnh Hello game 
	- 1.2 Sử dụng SDL_image để load ảnh
	- 1.3 Header Common để include các thư viện, lưu các biến toàn cục, các biến const,... (dùng chung)
	- 1.4 Texture Loading and Rendering
	- 1.5 Tạo global.h để lưu các biến global. Tạo BaseObject(đối tượng hình ảnh cơ sở) để các Object khác kế thừa
	- 1.6 ScreenObject màn hình game khi play, render g_Screen
	- 1.7 CharacterObject
		- 1.7.1 Render clips, thêm flip để lật ảnh theo hướng di chuyển
		- 1.7.2 Thêm di chuyển, ngẫu nhiên hướng di chuyển trái phải
	- 1.8 set Fps
* 2.0 Main Game (Game.h)
	- 2.1 Screen 1
		- 2.1.1 List character, size of list = LEVEL, ngẫu nhiên hình ảnh
		- 2.1.2 Xuất hiện lần lượt các character 