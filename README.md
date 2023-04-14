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
		- 2.1.1 List character1, size of list = LEVEL, ngẫu nhiên hình ảnh
		- 2.1.2 Xuất hiện lần lượt các character 
		
		https://user-images.githubusercontent.com/111406683/223747894-b5970f09-16a6-421a-be92-f5a9b5848502.mp4
		
	- 2.2 Move Screen sau khi kết thúc screen1
		- 2.2.1 add func handleMove cho ScreenObject,add func MoveScreen trong Game.h
		
		https://user-images.githubusercontent.com/111406683/223747936-d3fecda3-9896-43d5-a13a-6c5ce32988fa.mp4
	
	- 2.3 Screen 2
		- 2.3.1 Initalize list character2, check same between 2 character, list pos character list1 in list2
		- 2.3.2 Reset listcharacter2, xuất hiện lần lượt listCharacter2
		
		https://user-images.githubusercontent.com/111406683/224470247-c9438a7b-4a3b-4642-97f2-9de8211f54d4.mp4

		- 2.3.3 Thêm sellect của play với character (press Space to sellect), đếm số lần chọn đúng

		https://user-images.githubusercontent.com/111406683/228407369-399ad701-0cf6-45bf-a77b-a4ca71c8d291.mp4

		- 2.3.4 Thêm trạng thái game (game over, win, quit), chọn sai hoặc đúng nhưng không chọn (cơ hội cuối) thì GAME OVER, chọn đúng,đủ thì WIN

		https://user-images.githubusercontent.com/111406683/229077239-76dff1e8-9ba4-4b61-9714-077656f01bec.mp4

		- 2.3.5 TextObject Hiện lời hướng dẫn, hiện số lượt đã chọn đúng; cải tiến 1 số chỗ

		https://user-images.githubusercontent.com/111406683/229766990-f6195f6c-ee8e-4711-af76-1cb18e8ff346.mp4

* 3.0 Menu Game
	- 3.1 TextObject thêm tính năng nhận sự kiện chuột, đổi màu khi chuột trong vùng của text
	- 3.2 GameOver text GAMEOVER nhấp nháy, Button AGAIN và QUIT

	https://user-images.githubusercontent.com/111406683/230719449-183180dc-6ce1-49bf-a892-4f2f2a30cc67.mp4

	- 3.3 GameWin  text WIN nhấp nháy , button Next LEVEL và QUIT

	https://user-images.githubusercontent.com/111406683/230719424-17f727c1-2652-456c-a3d1-3f7f4bfe8edb.mp4
	
	- 3.4 StartGame button NEWGAME, QUIT, CONTINUE tiếp tục level cao nhất, SELLECT LEVEL
	- 3.5 SellectLevel button biểu tượng sang trái, phải để tăng giảm level

	https://user-images.githubusercontent.com/111406683/230719474-a51efb41-2221-42a6-88dd-f30cf25904bc.mp4

* 4.0 Sounds
	Âm thanh khi nhấn vào nút, game Over, game Win, countDown trong moveScreen

	https://user-images.githubusercontent.com/111406683/230900207-a2629763-e3f7-45b3-99d8-1438f7d0bfa1.mp4

* 5.0 Cải thiện
	- 5.1 Thêm button return menu ở gameover, gamewin, playagain ở screen
	

