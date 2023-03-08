# Telephone-Directory-to-manage-phone-number-
Trong thực tế mỗi người sẽ có nhiều hơn 1 SDT ( tối đa 3 SDT/nhà mạng) vì vậy cần xây dựng 1 ứng dụng quản lý danh bạ điện thoại với thông tin gồm
•	Họ tên hoặc bí danh
•	Danh sách các số điện thoại
•	Danh sách email
Danh bạ điện thoại để cho đơn giản sẽ lưu trữ bằng file text dưới format sau

3
Anh
Img:
T1:012356789
T2:022346789
Dung Huy
Img: data/dat1/person/img1.jpg
T1:012346789
E1:dung@dept.com.vn
Thuan Hoang
Img:
T1:040449444
E1:thuan12@gmail.com
E2:thuan233@soict.edu.vn

Trong đó 3 là số lượng contact và T1, E1 lần lượt là thông tin SDT và email
Img: trong trường hợp người đó có ảnh đại diện và ảnh được lưu trữ trên thư mục cụ bộ trên máy thì sẽ có đường dẫn tới file ảnh đó. Ngược lại thì trường này là để trống
Số lượng số điện thoại và email là không biết trước, thường là 1-2 nhưng cá biệt có thể nhiều hơn (cần xây dựng CTDL quản lý phù hợp để tiết kiệm bộ nhớ)	
Chương trình gồm có các yêu cầu sau
1.	Đọc và ghi thông tin danh bạ từ file theo format ở trên
2.	Tìm kiếm thông tin người trong danh bạ theo tên hoặc 1 phần tên (tìm gần đúng)
3.	Tra cứu xem 1 SDT đã có trong danh bạ hay chưa, nếu có thì trả về thông tin người đã có
4.	Xóa 1 người trong danh bạ
5.	Xóa 1 SDT trong danh bạ, nếu người đó chỉ có mỗi 1 SDT (không có email) thì xóa luôn tài khoản đó
6.	Cập nhật lại SDT, ảnh đại diện hoặc email trong danh bạ
Yêu cầu
•	Số lượng người trong danh bạ trên lý thuyết là vô hạn (tùy vào bộ nhớ), bạn nên cần có cách lưu trữ sao cho việc tìm kiếm là dễ dạng và tối ưu bộ nhớ
•	Số lượng truy vấn không thường xuyên (dùng cá nhân)
•	Ảnh đại diện để trong thư mục ngoại, chỉ cần cập nhật lại đường dẫn mỗi khi thay đổi (hoặc xóa đường dẫn)	
