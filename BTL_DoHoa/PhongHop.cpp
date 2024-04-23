#include "glut.h"
#include <iostream>

// Biến lưu trữ tọa độ chuột khi nhấn
int lastX = 0;
int lastY = 0;

GLfloat eyeX = 10.0, eyeY = 10.0, eyeZ = 50.0; // Vị trí ban đầu của camera

void DrawCoordinate()
{
	glDisable(GL_LIGHTING); //Tắt tính năng chiếu sáng 

	glLineWidth(1.0); // Đặt độ rộng của đường
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(50.0, 0.0, 0.0);
	glEnd();
	
	glLineWidth(1.0); // Đặt độ rộng của đường
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 50.0, 0.0);
	glEnd();

	glLineWidth(1.0); // Đặt độ rộng của đường
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 50.0);
	glEnd();

	glEnable(GL_LIGHTING);
}

void Brown() {
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient[] = { 0.8, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use[] = { 0.8, 0.6, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
}

void Black() {
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
}

void White() {
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
}

void SkyBlue() {
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient[] = { 0.0, 0.5, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use[] = { 0.0, 0.5, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
}

void Gray() {
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient[] = { 0.8, 0.8, 0.8, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use[] = { 0.8, 0.8, 0.8, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
}

void drawWall() {
	// màu
	White();

	// tường sau
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(15.0, 0.0, 0.0);
	glVertex3f(15.0, 8.0, 0.0);
	glVertex3f(0.0, 8.0, 0.0);
	glEnd();

	// tường trái
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 15.0);
	glVertex3f(0.0, 8.0, 15.0);
	glVertex3f(0.0, 8.0, 0.0);
	glEnd();

	// tường phải
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(15.0, 0.0, 0.0);
	glVertex3f(15.0, 0.0, 15.0);
	glVertex3f(15.0, 8.0, 15.0);
	glVertex3f(15.0, 8.0, 0.0);
	glEnd();
}

void drawFloorCell() {
	// màu
	Gray();

	// trần
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 8.0, 0.0);
	glVertex3f(15.0, 8.0, 0.0);
	glVertex3f(15.0, 8.0, 15.0);
	glVertex3f(0.0, 8.0, 15.0);
	glEnd();

	// sàn
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(15.0, 0.0, 0.0);
	glVertex3f(15.0, 0.0, 15.0);
	glVertex3f(0.0, 0.0, 15.0);
	glEnd();
}

void drawChair() {
	Brown();

	/// Ghế 1
	
	// Ghế
	glPushMatrix();
	glTranslatef(5.25, 1.3, 6.0);
	glScalef(1.5, 0.3, 1.5);
	glutSolidCube(1.0);
	glPopMatrix();

	// Chân
	glPushMatrix();
	glTranslatef(4.7, 0.65, 5.45);  // Di chuyển đến chân thứ nhất
	glScalef(0.2, 1.28, 0.2);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.8, 0.65, 5.45);  // Di chuyển đến chân thứ hai
	glScalef(0.2, 1.28, 0.2);   // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.8, 0.65, 6.55);  // Di chuyển đến chân thứ ba
	glScalef(0.2, 1.28, 0.2); // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.7, 0.65, 6.55);  // Di chuyển đến chân thứ tư
	glScalef(0.2, 1.28, 0.2);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	// Lưng
	glPushMatrix();
	glTranslatef(4.55, 2.15, 6.0);  // Di chuyển đến chân thứ tư
	glScalef(0.1, 1.7, 1.5);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	/// Ghế 2

	// Ghế
	glPushMatrix();
	glTranslatef(9.75, 1.3, 6.0);
	glScalef(1.5, 0.3, 1.5);
	glutSolidCube(1.0);
	glPopMatrix();

	// Chân
	glPushMatrix();
	glTranslatef(9.2, 0.65, 5.45);  // Di chuyển đến chân thứ nhất
	glScalef(0.2, 1.28, 0.2);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.3, 0.65, 5.45);  // Di chuyển đến chân thứ hai
	glScalef(0.2, 1.28, 0.2);   // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.3, 0.65, 6.55);  // Di chuyển đến chân thứ ba
	glScalef(0.2, 1.28, 0.2); // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.2, 0.65, 6.55);  // Di chuyển đến chân thứ tư
	glScalef(0.2, 1.28, 0.2);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	// Lưng
	glPushMatrix();
	glTranslatef(10.45, 2.15, 6.0);  // Di chuyển đến chân thứ tư
	glScalef(0.1, 1.7, 1.5);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();


	/// Ghế 3

	// Ghế
	glPushMatrix();
	glTranslatef(9.75, 1.3, 9.0);
	glScalef(1.5, 0.3, 1.5);
	glutSolidCube(1.0);
	glPopMatrix();

	// Chân
	glPushMatrix();
	glTranslatef(9.2, 0.65, 8.45);  // Di chuyển đến chân thứ nhất
	glScalef(0.2, 1.28, 0.2);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.3, 0.65, 8.45);  // Di chuyển đến chân thứ hai
	glScalef(0.2, 1.28, 0.2);   // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.3, 0.65, 9.55);  // Di chuyển đến chân thứ ba
	glScalef(0.2, 1.28, 0.2); // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.2, 0.65, 9.55);  // Di chuyển đến chân thứ tư
	glScalef(0.2, 1.28, 0.2);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	// Lưng
	glPushMatrix();
	glTranslatef(10.45, 2.15, 9.0);  // Di chuyển đến chân thứ tư
	glScalef(0.1, 1.7, 1.5);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();


	/// Ghế 4

	// Ghế
	glPushMatrix();
	glTranslatef(5.25, 1.3, 9.0);
	glScalef(1.5, 0.3, 1.5);
	glutSolidCube(1.0);
	glPopMatrix();

	// Chân
	glPushMatrix();
	glTranslatef(4.7, 0.65, 8.45);  // Di chuyển đến chân thứ nhất
	glScalef(0.2, 1.28, 0.2);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.8, 0.65, 8.45);  // Di chuyển đến chân thứ hai
	glScalef(0.2, 1.28, 0.2);   // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.8, 0.65, 9.55);  // Di chuyển đến chân thứ ba
	glScalef(0.2, 1.28, 0.2); // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.7, 0.65, 9.55);  // Di chuyển đến chân thứ tư
	glScalef(0.2, 1.28, 0.2);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	// Lưng
	glPushMatrix();
	glTranslatef(4.55, 2.15, 9.0);  // Di chuyển đến chân thứ tư
	glScalef(0.1, 1.7, 1.5);  // Kích thước
	glutSolidCube(1.0);
	glPopMatrix();
}

void drawTable() {
	Brown();

	// mặt bàn
	glPushMatrix();
	glTranslatef(7.5, 2.5, 7.5);
	glScalef(3.0, 0.5, 5.0);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp

	// chân bàn
	glPushMatrix();// Lưu ma trận hiện hành vào ngăn xếp
	glTranslatef(6.3, 1.3, 5.3);
	glScalef(0.3, 2.5, 0.3);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp

	glPushMatrix();// Lưu ma trận hiện hành vào ngăn xếp
	glTranslatef(8.7, 1.3, 5.3);
	glScalef(0.3, 2.5, 0.3);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp

	glPushMatrix();// Lưu ma trận hiện hành vào ngăn xếp
	glTranslatef(8.7, 1.3, 9.7);
	glScalef(0.3, 2.5, 0.3);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp

	glPushMatrix();// Lưu ma trận hiện hành vào ngăn xếp
	glTranslatef(6.3, 1.3, 9.7);
	glScalef(0.3, 2.5, 0.3);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp
}

void drawCabinet() {
	Brown();

	// tủ
	glPushMatrix();
	glTranslatef(1.1, 1.02, 3.26);
	glScalef(2.0, 2.0, 6.5);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp

	glLineWidth(2.0); // Đặt độ rộng của đường
	glBegin(GL_LINES);
	glVertex3f(2.1, 2.02, 4.5);
	glVertex3f(2.1, 0.02, 4.5);
	
	glVertex3f(2.1, 2.02, 2.5);
	glVertex3f(2.1, 0.02, 2.5);
	glEnd();
}

void drawShelf() {
	Brown();

	// kệ
	glPushMatrix();
	glTranslatef(13.89, 2.26, 0.2);
	glScalef(2.0, 4.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp

	glPushMatrix();
	glTranslatef(14.89, 2.3, 2.7);
	glScalef(0.1, 4.5, 5.0);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp

	glPushMatrix();
	glTranslatef(13.89, 2.26, 5.2);
	glScalef(2.0, 4.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp

	glPushMatrix();
	glTranslatef(13.89, 0.2, 2.7);
	glScalef(2.0, 0.1, 5.0);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp

	glPushMatrix();
	glTranslatef(13.89, 4.5, 2.7);
	glScalef(2.0, 0.1, 5.0);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp

	glPushMatrix();
	glTranslatef(13.89, 1.46, 2.7);
	glScalef(2.0, 0.1, 5.0);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp

	glPushMatrix();
	glTranslatef(13.89, 2.92, 2.7);
	glScalef(2.0, 0.1, 5.0);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp
}

void drawHolder() {
	Black();

	// tay nắm cửa
	glPushMatrix();
	glTranslatef(14.8, 2.7, 9.0);
	glutSolidSphere(0.1, 32.0, 32.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.2, 2.7, 9.0);
	glutSolidSphere(0.1, 32.0, 32.0);
	glPopMatrix();

	// tay nắm tủ
	glLineWidth(5.0); // Đặt độ rộng của đường
	glBegin(GL_LINES);
	glVertex3f(2.1, 1.01, 4.7);
	glVertex3f(2.1, 1.01, 4.9);
	
	glVertex3f(2.1, 1.01, 4.3);
	glVertex3f(2.1, 1.01, 4.1);
	glEnd();

	// giữ màn chiếu
	glPushMatrix();
	glTranslatef(7.5, 6.25, 0.26);
	glScalef(6.2, 0.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp
}

void drawDoor() {
	Brown();

	glPushMatrix();
	glTranslatef(15.0, 2.7, 8.0);
	glScalef(0.1, 5.49, 2.98);
	glColor3f(0.8, 0.4, 0.4);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp
}

void drawFrame() {
	Brown();

	glLineWidth(10.0); // Đặt độ rộng của đường
	glBegin(GL_LINES);

	// khung cửa sổ
	glVertex3f(0.0, 3.0, 5.5);
	glVertex3f(0.0, 3.0, 9.5);

	glVertex3f(0.0, 3.0, 9.5);
	glVertex3f(0.0, 7.0, 9.5);

	glVertex3f(0.0, 7.0, 9.5);
	glVertex3f(0.0, 7.0, 5.5);

	glVertex3f(0.0, 7.0, 5.5);
	glVertex3f(0.0, 3.0, 5.5);

	glVertex3f(0.0, 5.0, 5.5);
	glVertex3f(0.0, 5.0, 9.5);

	glVertex3f(0.0, 3.0, 7.5);
	glVertex3f(0.0, 7.0, 7.5);

	// khung cửa ra vào
	glVertex3f(15.0, 0.01, 6.5);
	glVertex3f(15.0, 5.51, 6.5);

	glVertex3f(15.0, 5.51, 6.5);
	glVertex3f(15.0, 5.51, 9.5);

	glVertex3f(15.0, 5.51, 9.5);
	glVertex3f(15.0, 0.01, 9.5);
	glEnd();

}

void drawWindow() {
	SkyBlue();

	glPushMatrix();
	glTranslatef(0.0, 5.0, 7.5);
	glScalef(0.01, 3.9, 3.9);
	glutSolidCube(1.0);
	glPopMatrix(); // Lấy ma trận gốc từ đỉnh của ngăn xếp
}

void drawCeilingLight() {
	White();

	glPushMatrix();
	glTranslatef(7.5, 7.5, 7.5);
	glutSolidSphere(0.4, 32.0, 32.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.5, 7.74, 7.5);
	glScalef(5.0, 0.5, 5.0);
	glutSolidCube(1.0);
	glPopMatrix();
}

void drawPaint() {
	SkyBlue();

	glPushMatrix();
	glTranslatef(14.85, 6.5, 3.5);
	glScalef(0.2, 1.2, 6.0);
	glutSolidCube(1.0);
	glPopMatrix();
}

void drawProjectScreen() {
	Gray();

	// màn chiếu
	glBegin(GL_QUADS);
	glVertex3f(4.5, 2.0, 0.25);
	glVertex3f(10.5, 2.0, 0.25);
	glVertex3f(10.5, 6.0, 0.25);
	glVertex3f(4.5, 6.0, 0.25);
	glEnd();
}

void drawTrashCan() {
	Gray();

	// Vẽ thân thùng rác (hình trụ)
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= 360; i += 10) {
		float angle = i * 3.1415926 / 180.0;
		glVertex3f((cos(angle) * 0.5) + 1.0, 0.02, (sin(angle) * 0.5) + 8.0);
		glVertex3f((cos(angle) * 0.5) + 1.0, 2.02, (sin(angle) * 0.5) + 8.0);
	}
	glEnd();

	// Vẽ đáy thùng rác
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i += 10) {
		float angle = i * 3.1415926 / 180.0;
		glVertex3f((cos(angle) * 0.5) + 1.0, 0.02, (sin(angle) * 0.5) + 8.0);
	}
	glEnd();
}

void drawBook() {
	//màu
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient1[] = { 1.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient1);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use1[] = { 1.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use1);
	glPushMatrix();
	glTranslatef(0.4, 2.5, 1.0);
	glScalef(0.6, 1.0, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//màu
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient2[] = { 0.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient2);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use2[] = { 0.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use2);
	glPushMatrix();
	glTranslatef(0.35, 2.6, 1.23);
	glScalef(0.5, 1.2, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//màu
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient3[] = { 0.0, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient3);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use3[] = { 0.0, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use3);
	glPushMatrix();
	glTranslatef(0.5, 2.5, 1.46);
	glScalef(0.8, 1.0, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//màu
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient4[] = { 1.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient4);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use4[] = { 1.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use4);
	glPushMatrix();
	glTranslatef(0.4, 2.5, 1.69);
	glScalef(0.6, 1.0, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//màu
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient5[] = { 1.0, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient5);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use5[] = { 1.0, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use5);
	glPushMatrix();
	glTranslatef(0.45, 2.4, 1.92);
	glScalef(0.7, 0.8, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//màu
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient6[] = { 0.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient6);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use6[] = { 0.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use6);
	glPushMatrix();
	glTranslatef(0.4, 2.5, 2.15);
	glScalef(0.6, 1.0, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//màu
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient7[] = { 0.0, 0.5, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient7);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use7[] = { 0.0, 0.5, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use7);
	glPushMatrix();
	glTranslatef(0.35, 2.6, 2.38);
	glScalef(0.5, 1.2, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//màu
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient8[] = { 0.5, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient8);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use8[] = { 0.5, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use8);
	glPushMatrix();
	glTranslatef(0.5, 2.5, 2.61);
	glScalef(0.8, 1.0, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//màu
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient9[] = { 0.4, 0.7, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient9);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use9[] = { 0.4, 0.7, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use9);
	glPushMatrix();
	glTranslatef(0.4, 2.5, 2.84);
	glScalef(0.6, 1.0, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//màu
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient10[] = { 0.7, 0.1, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient10);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use10[] = { 0.7, 0.1, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use10);
	glPushMatrix();
	glTranslatef(0.45, 2.4, 3.07);
	glScalef(0.7, 0.8, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//màu
	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient11[] = { 0.4, 0.6, 0.8, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient11);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use11[] = { 0.4, 0.6, 0.8, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use11);
	glPushMatrix();
	glTranslatef(0.5, 2.15, 4.1);
	glScalef(0.7, 0.3, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();
}

void ReShape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)width / (float)height;
	gluPerspective(30.0, ratio, 1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyPressed(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        glEnable(GL_LIGHT1);
        break;
    case '2':
        glEnable(GL_LIGHT2);
        break;
    case '3':
        glEnable(GL_LIGHT3);
        break;
	case '4':
		glDisable(GL_LIGHT1);
		break;
	case '5':
		glDisable(GL_LIGHT2);
		break;
	case '6':
		glDisable(GL_LIGHT3);
		break;
	case 'q':
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);
		glEnable(GL_LIGHT3);
		break;
	case 'e':
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		break;
    case 'u':
        eyeX += 0.1;
        break;
    case 'i':
        eyeY += 0.1;
        break;
    case 'o':
        eyeZ += 0.1;
        break;
    case 'j':
        eyeX -= 0.1;
        break;
    case 'k':
        eyeY -= 0.1;
        break;
    case 'l':
        eyeZ -= 0.1;
        break;
    }
    glutPostRedisplay(); // Yêu cầu cập nhật lại màn hình
}

void Init()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
	

	// Nguồn 1
	float light_pos1[] = { 7.5, 7.5, 7.5, 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, light_pos1);
	GLfloat ambient1[] = { 0.2, 0.2, 0.0, 1.0 };
	GLfloat diffuse1[] = { 0.2, 0.2, 0.0, 1.0 };
	GLfloat specular1[] = { 0.2, 0.2, 0.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);

	//GL_SPOT_EXPONENT: độ tỏa rộng của vùng sáng mờ hay độ tập trung chùm sáng
	// -giá trị càng cao vùng sáng càng sắc nét (chùm sáng tập trung vào một vùng diện tích nhỏ)
	// -giá trị càng thấp vùng sáng càng mờ (chùm sáng tỏa rộng ra diện tích lớn hơn)
	GLfloat spotExp1 = 100.0;
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, spotExp1);
	//GL_SPOT_CUTOFF: góc chiếu giới hạn
	//- giá trị càng nhỏ: góc chiếu càng hẹp, tạo ra chùm sáng hẹp
	//- giá trị càng lớn: góc chiếu càng lớn, vùng được chiếu sáng càng rộng
	GLfloat spotCutoff1 = 100.0;
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, spotCutoff1);
	//GL_SPOT_DIRECTION: hướng chiếu sáng của nguồn sáng dạng spot
	float light_dir1[3] = {0.0, -1.0, 0.0 };
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_dir1); 


	// Nguồn 2
	float light_pos2[] = { 7.5, 4.0, 0.1, 1.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos2);
	GLfloat ambient2[] = { 0.0, 0.2, 0.2, 1.0 };
	GLfloat diffuse2[] = { 0.0, 0.2, 0.2, 1.0 };
	GLfloat specular2[] = { 0.0, 0.2, 0.2, 1.0 };
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specular2);

	//GL_SPOT_EXPONENT: độ tỏa rộng của vùng sáng mờ hay độ tập trung chùm sáng
	// -giá trị càng cao vùng sáng càng sắc nét (chùm sáng tập trung vào một vùng diện tích nhỏ)
	// -giá trị càng thấp vùng sáng càng mờ (chùm sáng tỏa rộng ra diện tích lớn hơn)
	GLfloat spotExp2 = 20.0;
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, spotExp2);
	//GL_SPOT_CUTOFF: góc chiếu giới hạn
	//- giá trị càng nhỏ: góc chiếu càng hẹp, tạo ra chùm sáng hẹp
	//- giá trị càng lớn: góc chiếu càng lớn, vùng được chiếu sáng càng rộng
	GLfloat spotCutoff2 = 30.0;
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, spotCutoff2);
	//GL_SPOT_DIRECTION: hướng chiếu sáng của nguồn sáng dạng spot
	float light_dir2[3] = { 0.0, 0.0,- 1.0 };
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_dir2);


	// Nguồn 3
	float light_pos3[] = { -15.0, 10.0, 3.75, 1.0 };
	glLightfv(GL_LIGHT3, GL_POSITION, light_pos3);
	GLfloat ambient3[] = { 0.2, 0.0, 0.2, 1.0 };
	GLfloat diffuse3[] = { 0.2, 0.0, 0.2, 1.0 };
	GLfloat specular3[] = { 0.2, 0.0, 0.2, 1.0 };
	glLightfv(GL_LIGHT3, GL_AMBIENT, ambient3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, specular3);

	//GL_SPOT_EXPONENT: độ tỏa rộng của vùng sáng mờ hay độ tập trung chùm sáng
	// -giá trị càng cao vùng sáng càng sắc nét (chùm sáng tập trung vào một vùng diện tích nhỏ)
	// -giá trị càng thấp vùng sáng càng mờ (chùm sáng tỏa rộng ra diện tích lớn hơn)
	GLfloat spotExp3 = 50.0;
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, spotExp3);
	//GL_SPOT_CUTOFF: góc chiếu giới hạn
	//- giá trị càng nhỏ: góc chiếu càng hẹp, tạo ra chùm sáng hẹp
	//- giá trị càng lớn: góc chiếu càng lớn, vùng được chiếu sáng càng rộng
	GLfloat spotCutoff3 = 100.0;
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, spotCutoff3);
	//GL_SPOT_DIRECTION: hướng chiếu sáng của nguồn sáng dạng spot
	float light_dir3[3] = { 1.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light_dir3);
}

void mouseButton(int button, int state, int x, int y) {
	// Lưu lại tọa độ chuột khi nhấn
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		lastX = x;
		lastY = y;
	}
}

void mouseMove(int x, int y) {
	// Tính toán sự chênh lệch tọa độ chuột
	int deltaX = x - lastX;
	int deltaY = y - lastY;

	// Cập nhật tọa độ camera
	eyeX += deltaX * 0.1;
	eyeY -= deltaY * 0.1; // Đảo chiều trục y để phù hợp với hệ tọa độ

	lastX = x;
	lastY = y;

	glutPostRedisplay();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // xóa nội dung của các bộ đệm màu (color buffer) và bộ đệm độ sâu (depth buffer) 
	glLoadIdentity();// Thiết lập ma trận modelview về ma trận đơn vị

	gluLookAt(eyeX, eyeY, eyeZ,
		0.0, 0.0, 0.0,
		0.0, 50.0, 0.0); // Cập nhật hướng nhìn

	glPushMatrix();// Lưu ma trận hiện hành vào ngăn xếp
	DrawCoordinate();

	drawWall(); // vẽ tường

	drawFloorCell(); // vẽ trần và nền

	drawTable(); // vẽ bàn

	drawChair(); // vẽ ghế

	drawCabinet(); // vẽ tủ

	drawShelf(); // vẽ kệ

	drawDoor(); // vẽ cửa

	drawFrame(); // vẽ khung

	drawHolder(); // vẽ tay nắm

	drawWindow(); // vẽ kính cửa sổ

	drawProjectScreen(); // vẽ nàm chiếu

	drawTrashCan(); // vẽ thùng rác

	drawCeilingLight(); // vẽ đèn trần

	drawPaint(); // vẽ tranh

	drawBook(); // vẽ sách

	glFlush();
}

void main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Phòng họp");

	Init();
	glutReshapeFunc(ReShape);
	glutDisplayFunc(Display);

	glutKeyboardFunc(keyPressed); // Đăng ký hàm xử lý sự kiện nhấn phím

	// Đăng ký các hàm xử lý sự kiện chuột
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	glutMainLoop();

}