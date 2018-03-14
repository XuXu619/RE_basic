    í dụ khai báo:
        float x, y;

    Cho ta hai biến kiểu float với các tên là x và y. Ta cũng sẽ làm y hệt như vậy khi khai báo biến cấu trúc. Giả sử ta đã có ác kiểu cấu trúc ngay va nhan_cong như trong các ví dụ 1.1 và 1.2 khi đó ta có thể xét các ví dụ sau:

    Ví dụ 2.1 : Khai báo
        struct ngay ngay_di, ngay_den;

    Sẽ cho ta hai biến cấu trúc với tên là ngay_di và ngay_den. Cả hai đều được xây dựng theo kiểu ngay.

    Ví dụ 2.2 : Khai báo
        `struct nhan_cong, nguoi_a, nguoi_b;

    Sẽ cho ta hai cáu trúc với tên là nguoi_a và nguoi_b. Cả hai đều được xây dựng theo kieu nhan_cong

    Một cách tổng quát, việc khai báo cấu trúc được thực hiện theo mẫu:

    `struct tên_kiểu_cấu_trúc danh_sách_tên_cấu_trúc;

    Sau đây là một vài điều cần lưu ý:
        Nhận xét 2.1: Các biến cấu trúc được khai báo theo mẫu trên sẽ được cấp phát bộ nhớ một cách đầy đủ cho tất cả các thành phàn của nó.
        Nhận xét 2.2: Việc khai báo có thể thực hiện đồng thời với việc dịnh nghĩa kiểu cấu trúc. Muốn vậy chỉ cần đặt danh sách tên biến cấu trúc cần khai báo vào sau } cuối cùng trong mẫu 1.1

    Nói cách khác: Đề vừa thiết kế kiểu vừa khai báo các biến cấu trúc ta sử dụng mẫu sau:

    Mẫu 2.2

struct ten_kiểu_cấu_trúc
{
	các thành phần cảu cấu trúc
} danh sách tên biến cấu trúc

    Ví dụ 2.3: Các cấu trúc ngay_di và ngay_den trong ví dụ 2.1 có thể được xây dựng theo cách:

struct ngay
{
	int ngay_thu;
	char ten_thang[10];
	int nam;
} ngay_di, ngay_den;

    Ví dụ 2.4: Các cấu trúc nguoi_a, nguoi_b trong ví dụ 2.2 có thể xây dựng theo mẫu sau (giải sử kiểu ngay đẫ được mô tả như ở ví dụ 1.1)

struct nhan_cong
{
	char ten[15];
	char dia_chi[20];
	double bac_luong;
	struct ngay ngay_sinhl
	struct ngay ngay_vao_co_quan;
} nguoi_a, nguoi_b;

    Nhận xét 2.3 : Khi vừa định nghĩa kiểu (cấu trúc) vừa khai báo cấu trúc như trong ví dụ 2.3 và 2.4 ta có thể không cần đến tên kiểu cấu trúc. Nói cách khác các cấu trúc có thể được khai báo theo mẫu sau.

    Mẫu 2.3 :

struct
{
	các thành phần cảu cấu trúc
} danh sách tên cấu trúc;

    Ví dụ 2.5: Các cấu trúc ngay_di và ngay_den trong ví dụ 2.3 được khai báo theo cách:

struct
{
	int ngay_thu;
	char ten_thang[10];
	int nam;
} ngay_di, ngay_den;

    Cũng cần nói thêm sự khác nhau giữa mẫu 2.2 và mẫu 2.3. Điều ngày sẽ trở nên hoàn toàn rõ ràng khi so sánh ví dụ 2.3 và ví dụ 2.5 ở ví dụ 2.3 ngoài việc xây dựng được cấcc cấu trúc ngay_di, ngay_den ta còn cho ra đời được kiểu cấu trúc ngay. Kieẻu ngay có thể sử dụng để khai báo ở các cấu trúc khác. Ỏ ví dụ 2.4 ta chỉ đặt được mục đích đầu của ví dụ 2.3.

    Chú ý: Nếu dùng typedef để định nghĩa kiểu cấu trúc, thì khi khai báo ta chỉ cần dùng tên kiểu (bỏ từ khoá struct). Ví dụ như kiểu cấu trúc ngay dược định như trong chú ý 1.1 của 2.1 thì các cấu trúc ngay_di và ngay_den trong ví dụ 2.1 có thể khai báo như sau:

    ngay ngay_di, ngay_den;
