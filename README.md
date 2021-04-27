

                             	      GAME: Ô ĂN QUAN
				   				  
	    	  Author: Hoàng Phan Hữu Đức                  MSV: 20020011           LHP: INT2215_6

<<<<<<< HEAD
	Author: Hoàng Phan Hữu Đức                MSV: 20020011    

   
   1. Giới thiệu game: 
	Board game ô ăn quan với 2 chế độ chơi gồm chơi gồm chơi với máy (có 3 mức độ) và chơi với người. Luật 
chơi dựa trên luật ô ăn quan cơ bản (1 quan = 10 dân, nước đầu không ăn quan, ...), có thể tìm hiểu ở 
>>>>>>> 3aa5e68442d4ab2ef37896d0dbea595a6ae59d41
https://vi.wikipedia.org/wiki/%C3%94_%C4%83n_quan
    2. Mô tả game:
	- Đồ họa và âm thanh đầy đủ, giao diện đơn giản dễ nhìn
	- Game thiết kế chặt chẽ theo luật ô ăn quan
	- Chế độ chơi với máy sử dụng thuật toán minimax để tìm nước đi tốt nhất trong một giới hạn 
độ sâu (3 mức độ sẽ sử dụng 3 độ sâu tăng dần)
    3. Mô tả công việc:
	- Chia game ra thành các file header và cpp để code, bao gồm phần xây đựng đồ họa, âm thanh, phần
board và thiết kế luật chơi, phần gameplay bao gồm người và máy, phần menu, ...
	- Code không tham khảo từ sources code nào (tự code), dựa trên reference từ https://www.libsdl.org/ 
và https://lazyfoo.net/tutorials/SDL/ 
    4. Hướng phát triển
	- Thuật toán cho bot ở chế độ máy có thể được tối ưu hơn (có thể sử dụng các thuật toán tối ưu hóa
cho việc tìm kiếm theo độ sâu như tham lam, branch and cut, ...
	- Nước đi và lối chơi của bot có thể viết thành 1 file header -> có thể tạo ra chế độ đấu thuật toán
qua việc tạo các bot và nhúng vào khung game hiện có (chế độ bot vs bot)
    
=======
	
	1. Giới thiệu game: 
		Board game ô ăn quan với 2 chế độ chơi gồm chơi gồm chơi với máy (có 3 mức độ) và chơi với người. Luật 
	chơi dựa trên luật ô ăn quan cơ bản (1 quan = 10 dân, nước đầu không ăn quan, ...), có thể tìm hiểu ở 
	https://vi.wikipedia.org/wiki/%C3%94_%C4%83n_quan
   	 2. Mô tả game:
		- Đồ họa và âm thanh đầy đủ, giao diện đơn giản dễ nhìn
		- Game thiết kế chặt chẽ theo luật ô ăn quan
		- Chế độ chơi với máy sử dụng thuật toán minimax để tìm nước đi tốt nhất trong một giới hạn 
	độ sâu (3 mức độ sẽ sử dụng 3 độ sâu tăng dần)
   	 3. Mô tả công việc:
		- Chia game ra thành các file header và cpp để code, bao gồm phần xây đựng đồ họa, âm thanh, phần
		board và thiết kế luật chơi, phần gameplay bao gồm người và máy, phần menu, ...
		- Code không tham khảo từ sources code nào (tự code), dựa trên reference từ https://www.libsdl.org/ 
		và https://lazyfoo.net/tutorials/SDL/ 
   	 4. Hướng phát triển
		- Thuật toán cho bot ở chế độ máy có thể được tối ưu hơn (có thể sử dụng các thuật toán tối ưu hóa
		cho việc tìm kiếm theo độ sâu như tham lam, branch and cut, ...
		- Nước đi và lối chơi của bot có thể viết thành 1 file header -> có thể tạo ra chế độ đấu thuật toán
		qua việc tạo các bot và nhúng vào khung game hiện có (chế độ bot vs bot)  

  
>>>>>>> f662d493078cb9f03bf8f7f0b487fbd8765be099
    => Với việc đáp ứng các yêu cầu về bài tập lớn, em xin tự đánh giá số điểm cho game là khoảng 9.5-10 điểm

