#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<graphics.h>
#include<easyx.h>

using namespace std;
const int INF = 99999999;
//ÿ��Ҫʹ�ù���ʱ����ʼ��һ��schoolmap����
class schoolmap{
private:
	vector<vector<int>>Nankaigraph;//�ڽӾ���
	vector<int>dist;//�������·�����ȵ�����
	vector<int>path;//��¼���·���߷�������
	vector<int>q;//��¼����·���߷�������
	int sum;//��¼·������

public:
	//�ж��Ƿ��ǹ����ĵ�ĺ���
	bool if_isloated(int a) {
		for (int i = 0; i < Nankaigraph[0].size(); i++) {
			if (i != a) {
				if (Nankaigraph[a][i] != INF) {
					return false;
				}
			}
		}
		return true;
	}
	//���·������
	void Dijkstra(int start, int goal) {
		cout<<endl;
		//����³����
		//���������һ���ǹ����ĵ������
		if (if_isloated(start) || if_isloated(goal)) {
			cout << start << "=>" << goal << "��·��" << endl;
			return;
		}
		
		//�ձ����
		int n = Nankaigraph[0].size();//n�������еĽ����
		vector<int>dist(n, 0);
		vector<int>visit1(n, 0);
		vector<int>path(n, -1);//�ֱ���г�ʼ��
		for (int i = 0; i < n; i++) {
			dist[i] = Nankaigraph[start][i];//��ʼ��dist����Ϊ���ͼ�еĳ���
		}
		visit1[start] = 1;//����ʼ�ڵ���Ϊ��ʹ��
		for (int i = 0; i < n; i++) {
			int mindist = INF;
			int temp = 0;
			for (int j = 0; j < n; j++) {
				if (visit1[j] == 0 && mindist > dist[j]) {
					mindist = dist[j];
					temp = j;
				}
			}
			visit1[temp] = 1;
			for (int j = 0; j < n; j++) {
				if (visit1[j] == 0 && dist[j] > dist[temp] + Nankaigraph[temp][j]) {
					dist[j] = dist[temp] + Nankaigraph[temp][j];
					path[j] = temp;
				}
			}
		}

		stack<int>q1;
		int j = goal;
		while (path[j] != -1)      //���j����;�ڵ�
		{
			q1.push(j);          //��jѹ���
			j = path[j];          //��j��ǰ����;�ڵ㸳��j
		}
		q1.push(j);
		
		printf("%d=>%d, ���·������Ϊ:%d, ���·��Ϊ: %d ", start, goal, dist[goal], start);
		while (!q1.empty())       //�Ƚ����,�������
		{
			printf("%d ", q1.top());//��ӡ�ѵ�ͷ�ڵ�
			q1.pop();     //���ѵ�ͷ�ڵ㵯��
		}
		printf("\n");
	}
	//����·������
	void DFS(int start, int goal, vector<int>visit) {
		if (if_isloated(start) || if_isloated(goal)) {
			cout << start << "=>" << goal << "��·��" << endl;
			return;
		}
		visit.at(start) = 1;
		q.push_back(start);
		if (goal == start) {
			sum++;
			cout << endl << "��" << sum << "��·��Ϊ��" << q.at(0);
			for (int i = 1; i < q.size(); i++) {
				cout << "=>" << q.at(i);
			}
		}
		else {
			for (int i = 0; i < Nankaigraph[0].size(); i++) {
				if (visit[i] == 0 && Nankaigraph[start][i] < INF) {
					DFS(i, goal, visit);
				}
			}
		}
		q.pop_back();
		visit[start] = 0;
		return;//�˳��ò�ݹ飻
	}
	//���캯��
	schoolmap (vector<vector<int>>& Graph) {
		Nankaigraph = Graph;
		sum = 0;
	}
};

//�������·����ť����
void button1(int x, int y, int w, int h) {
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(126, 12, 110));//�Ͽ���ר��
	fillroundrect(x, y, x + w, y + h, 30,30);
	
	//����������
	settextstyle(30, 0, "����");
	int tx = x + (w - textwidth("���·��"))/2;
	int ty = y + (h - textheight("���·��")) / 2;
	settextcolor(BLACK);
	outtextxy(tx, ty, "���·��");
}

//��������·����ť����
void button2(int x, int y, int w, int h) {
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(126, 12, 110));//�Ͽ���ר��
	fillroundrect(x, y, x + w, y + h, 30, 30);

	//����������
	settextstyle(30, 0, "����");
	int tx = x + (w - textwidth("����·��")) / 2;
	int ty = y + (h - textheight("����·��")) / 2;
	settextcolor(BLACK);
	outtextxy(tx, ty, "����·��");
}

//���ƽ���У����ť����
void button3(int x, int y, int w, int h) {
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(126, 12, 110));//�Ͽ���ר��
	fillroundrect(x, y, x + w, y + h, 30, 30);

	//����������
	settextstyle(30, 0, "����У��");
	int tx = x + (w - textwidth("����У��")) / 2;
	int ty = y + (h - textheight("����У��")) / 2;
	settextcolor(BLACK);
	outtextxy(tx, ty, "����У��");
}

//���ư���̨У����ť����
void button4(int x, int y, int w, int h) {
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(126, 12, 110));//�Ͽ���ר��
	fillroundrect(x, y, x + w, y + h, 30, 30);

	//����������
	settextstyle(30, 0, "����");
	int tx = x + (w - textwidth("����̨У��")) / 2;
	int ty = y + (h - textheight("����̨У��")) / 2;
	settextcolor(BLACK);
	outtextxy(tx, ty, "����̨У��");
}

//���������ť����
void button5(int x, int y, int w, int h) {
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(126, 12, 110));//�Ͽ���ר��
	fillroundrect(x, y, x + w, y + h, 30, 30);

	//����������
	settextstyle(30, 0, "����");
	int tx = x + (w - textwidth("���")) / 2;
	int ty = y + (h - textheight("���")) / 2;
	settextcolor(BLACK);
	outtextxy(tx, ty, "���");
}



//���Ƶ�ĺ���
void clickbig(int x,int y) {
	setfillcolor(BLACK);
	solidcircle(x, y, 9);
}

//�������Ϊ��ɫ
void clickbig1(int x, int y) {
	setfillcolor(GREEN);
	solidcircle(x, y, 9);
}

//����յ��Ϊ��ɫ
void clickbig2(int x, int y) {
	setfillcolor(RED);
	solidcircle(x, y, 9);
}

//������
int main() {
	vector<vector<int>>Nankai;
	Nankai.resize(12);
	for (int i = 0; i < 12; i++) {
		Nankai[i].resize(12);
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			Nankai[i][j] = i == j ? 0 : INF;
		}
	}
	/*Nankai[0][1] = 360; Nankai[0][5] = 410; Nankai[1][2] = 45;
	Nankai[2][5] = 80; Nankai[2][6] = 90; Nankai[3][4] = 380;
	Nankai[3][7] = 125; Nankai[4][7] = 276; Nankai[4][8] = 278;
	Nankai[5][6] = 60; Nankai[6][8] = 235; Nankai[6][10] = 432;
	Nankai[7][9] = 250; Nankai[8][10] = 140; Nankai[9][10] = 482;
	Nankai[9][11] = 658; Nankai[10][11] = 65;*/

	Nankai[0][1] = 360; Nankai[0][5] = 410; Nankai[1][2] = 45;
	Nankai[2][5] = 80; Nankai[2][6] = 90; Nankai[3][4] = 380;
	Nankai[3][7] = 125; Nankai[4][7] = 276; Nankai[4][8] = 278;
	Nankai[5][6] = 60; Nankai[6][8] = 235; Nankai[6][10] = 432;
	Nankai[7][9] = 250; Nankai[8][10] = 140; Nankai[9][10] = 482;//�����ݺ�������11������֤����³����
	
	
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (j > i) { Nankai[j][i] = Nankai[i][j]; }
		}
	}//�Խ��ϵ�����ͼ�ڽӾ����ʼ�����


	vector<vector<int>>Nankai1;
	Nankai1.resize(10);
	for (int i = 0; i < 10; i++) {
		Nankai1[i].resize(10);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Nankai1[i][j] = i == j ? 0 : INF;
		}
	}
	Nankai1[0][1] = 420; Nankai1[0][3] = 1264; Nankai1[0][6] = 567;
	Nankai1[0][9] = 1998; Nankai1[1][2] = 218; Nankai1[1][4] = 347;
	Nankai1[1][6] = 678; Nankai1[2][4] = 187; Nankai1[2][5] = 209;
	Nankai1[3][5] = 202; Nankai1[3][9] = 289; Nankai1[4][5] = 234;
	Nankai1[4][6] = 864; Nankai1[4][7] = 401; Nankai1[4][8] = 256;
	Nankai1[5][8] = 198; Nankai1[5][9] = 245; Nankai1[6][7] = 645;
	Nankai1[7][8] = 460; Nankai1[8][9] = 222;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j > i) { Nankai1[j][i] = Nankai1[i][j]; }
		}
	}
	//�԰���̨������ͼ�ڽӾ����ʼ�����

	//������ʼ����
	initgraph(1200, 900, EW_NOMINIMIZE);//����һ������,������xΪ800��yΪ1200
	setbkcolor(WHITE);
	cleardevice();
	IMAGE imag;
	loadimage(&imag, "./nankai.jpg", 400, 400);
	putimage(400, 0, &imag);
	settextstyle(50, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(400, 400, "��ӭ�����Ͽ���ѧ");
	outtextxy(400, 500, "��ѡ����Ҫȥ��У��");
	button3(500, 600, 200, 80);
	button4(500, 720, 200, 80);

	ExMessage emsg;
	while (true) {
		ExMessage emsg;
		if (peekmessage(&emsg, EM_MOUSE)) {
			switch (emsg.message) {
			case  WM_LBUTTONDOWN:

				//���ѡ�����У��
				if (emsg.x > 500 && emsg.x < 700 && emsg.y>600 && emsg.y < 680) {
					initgraph(1200, 800, EW_SHOWCONSOLE);//����һ������,������xΪ800��yΪ1200
					setbkcolor(WHITE);
					cleardevice();
					IMAGE img;//����һ��img�Ķ���
					loadimage(&img, "./schoolmap1.jpg", 800, 500);
					putimage(0, 0, &img);

					clickbig(388, 75); clickbig(568, 125); clickbig(634, 122); clickbig(251, 215); clickbig(463, 212); clickbig(614, 197);
					clickbig(684, 195); clickbig(326, 263); clickbig(569, 253); clickbig(205, 360); clickbig(571, 366); clickbig(571, 476);
						
					//��ť�ķ���
					button1(900, 100, 150, 80);
					button2(900, 300, 150, 80);
					button5(900, 500, 150, 80);
					int start1 = INF; int end1 = INF;
					ExMessage msg;
					while (true) {
						if (peekmessage(&msg, EM_MOUSE)) {
							switch (msg.message) {
								//������� 0��388 75��1��568 125��2��634 122��
									 //3��251 215��4��463 212��5��614 197��6��684 195��7��326 263��
									 //8��569 253��9��205 360��10��571 366��11��571 476
							case WM_LBUTTONDOWN:
							{
								if (msg.x > 900 && msg.x < 1050 && msg.y>100 && msg.y < 180) {
									//������ʾ������ʾ���·����
									HWND hnd1 = GetHWnd();


									//���·��������жϣ��Ƿ���ѡ����ʼλ�ú���ֹλ��
									//δѡ�񵯳���ʾ��
									if (end1 == INF || start1 == INF) {
										MessageBox(hnd1, "������������������㣬����Ҽ��������յ�", "��ʾ", MB_OKCANCEL);
									}
									//��ѡ�񵯳������
									else {
										if (end1 == start1) {
											MessageBox(hnd1, "�����յ㲻���غ�Ŷ", "��ʾ", MB_OKCANCEL);
										}
										else {
											HWND hnd1 = GetHWnd();
											MessageBox(hnd1, "���·��������ڿ���̨", "��ʾ", MB_OKCANCEL);
											schoolmap A(Nankai);
											A.Dijkstra(start1, end1);
										}
									}	
								}
								else if (msg.x > 900 && msg.x < 1050 && msg.y>300 && msg.y < 380) {
									HWND hnd1 = GetHWnd();
									if (end1 == INF || start1 == INF) {
										MessageBox(hnd1, "������������������㣬����Ҽ��������յ�", "��ʾ", MB_OKCANCEL);
									}
									else {
										if (start1 == end1) {
											MessageBox(hnd1, "�����յ㲻���غ�Ŷ", "��ʾ", MB_OKCANCEL);
										}
										else{
											HWND hnd1 = GetHWnd();
											MessageBox(hnd1, "����·��������ڿ���̨", "��ʾ", MB_OKCANCEL);
											schoolmap A(Nankai);
											vector<int>Visit(Nankai[0].size(), 0);
											A.DFS(start1, end1, Visit);
										}
									}
								}
								else if (msg.x > 900 && msg.x < 1050 && msg.y>500 && msg.y < 580) {
									clickbig(388, 75); clickbig(568, 125); clickbig(634, 122); clickbig(251, 215); clickbig(463, 212); clickbig(614, 197);
									clickbig(684, 195); clickbig(326, 263); clickbig(569, 253); clickbig(205, 360); clickbig(571, 366); clickbig(571, 476);
									HWND hnd1 = GetHWnd();
									MessageBox(hnd1, "�����յ�������", "��ʾ", MB_OKCANCEL);
									start1 = INF; end1 = INF;
								}
								//��ʼ�ڵ��ѡ��
								if (msg.x > 388 - 6 && msg.x < 388 + 6 && msg.y>75 - 6 && msg.y < 75 + 6) {
									if (start1 != INF) {
										if(start1==0){ clickbig(388, 75); }
										else if(start1==1){ clickbig(568, 125); }
										else if(start1==2){ clickbig(634, 122); }
										else if(start1==3){ clickbig(251, 215); }
										else if(start1==4){ clickbig(463, 212); }
										else if(start1==5){ clickbig(614, 197); }
										else if (start1 == 6){ clickbig(684, 195); }
										else if (start1 == 7){ clickbig(326, 263); }
										else if(start1==8){ clickbig(569, 253); }
										else if(start1==9){ clickbig(205, 360); }
										else if(start1==10){ clickbig(571, 366); }
										else if(start1==11){ clickbig(571, 476); }
									}
									start1 = 0;
									clickbig1(388, 75);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ0���Ŀ���������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 568 - 6 && msg.x < 568 + 6 && msg.y>125 - 6 && msg.y < 125 + 6) {
									if (start1 != INF) {
										if (start1 == 0) { clickbig(388, 75); }
										else if (start1 == 1) { clickbig(568, 125); }
										else if (start1 == 2) { clickbig(634, 122); }
										else if (start1 == 3) { clickbig(251, 215); }
										else if (start1 == 4) { clickbig(463, 212); }
										else if (start1 == 5) { clickbig(614, 197); }
										else if (start1 == 6) { clickbig(684, 195); }
										else if (start1 == 7) { clickbig(326, 263); }
										else if (start1 == 8) { clickbig(569, 253); }
										else if (start1 == 9) { clickbig(205, 360); }
										else if (start1 == 10) { clickbig(571, 366); }
										else if (start1 == 11) { clickbig(571, 476); }
									}
									start1 = 1;
									clickbig1(568, 125);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ1��������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 634 - 6 && msg.x < 634 + 6 && msg.y>122 - 6 && msg.y < 122 + 6) {
									if (start1 != INF) {
										if (start1 == 0) { clickbig(388, 75); }
										else if (start1 == 1) { clickbig(568, 125); }
										else if (start1 == 2) { clickbig(634, 122); }
										else if (start1 == 3) { clickbig(251, 215); }
										else if (start1 == 4) { clickbig(463, 212); }
										else if (start1 == 5) { clickbig(614, 197); }
										else if (start1 == 6) { clickbig(684, 195); }
										else if (start1 == 7) { clickbig(326, 263); }
										else if (start1 == 8) { clickbig(569, 253); }
										else if (start1 == 9) { clickbig(205, 360); }
										else if (start1 == 10) { clickbig(571, 366); }
										else if (start1 == 11) { clickbig(571, 476); }
									}
									start1 = 2;
									clickbig1(634, 122);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ2����������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 251 - 6 && msg.x < 251 + 6 && msg.y>215 - 6 && msg.y < 215 + 6) {
									if (start1 != INF) {
										if (start1 == 0) { clickbig(388, 75); }
										else if (start1 == 1) { clickbig(568, 125); }
										else if (start1 == 2) { clickbig(634, 122); }
										else if (start1 == 3) { clickbig(251, 215); }
										else if (start1 == 4) { clickbig(463, 212); }
										else if (start1 == 5) { clickbig(614, 197); }
										else if (start1 == 6) { clickbig(684, 195); }
										else if (start1 == 7) { clickbig(326, 263); }
										else if (start1 == 8) { clickbig(569, 253); }
										else if (start1 == 9) { clickbig(205, 360); }
										else if (start1 == 10) { clickbig(571, 366); }
										else if (start1 == 11) { clickbig(571, 476); }
									}
									start1 = 3;
									clickbig1(251, 215);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ3�������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 463 - 6 && msg.x < 463 + 6 && msg.y>212 - 6 && msg.y < 212 + 6) {
									if (start1 != INF) {
										if (start1 == 0) { clickbig(388, 75); }
										else if (start1 == 1) { clickbig(568, 125); }
										else if (start1 == 2) { clickbig(634, 122); }
										else if (start1 == 3) { clickbig(251, 215); }
										else if (start1 == 4) { clickbig(463, 212); }
										else if (start1 == 5) { clickbig(614, 197); }
										else if (start1 == 6) { clickbig(684, 195); }
										else if (start1 == 7) { clickbig(326, 263); }
										else if (start1 == 8) { clickbig(569, 253); }
										else if (start1 == 9) { clickbig(205, 360); }
										else if (start1 == 10) { clickbig(571, 366); }
										else if (start1 == 11) { clickbig(571, 476); }
									}
									start1 = 4;
									clickbig1(463, 212);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ4������¥", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 614 - 6 && msg.x < 614 + 6 && msg.y>197 - 6 && msg.y < 197 + 6) {
								if (start1 != INF) {
									if (start1 == 0) { clickbig(388, 75); }
									else if (start1 == 1) { clickbig(568, 125); }
									else if (start1 == 2) { clickbig(634, 122); }
									else if (start1 == 3) { clickbig(251, 215); }
									else if (start1 == 4) { clickbig(463, 212); }
									else if (start1 == 5) { clickbig(614, 197); }
									else if (start1 == 6) { clickbig(684, 195); }
									else if (start1 == 7) { clickbig(326, 263); }
									else if (start1 == 8) { clickbig(569, 253); }
									else if (start1 == 9) { clickbig(205, 360); }
									else if (start1 == 10) { clickbig(571, 366); }
									else if (start1 == 11) { clickbig(571, 476); }
								}
									start1 = 5;
									clickbig1(614, 197);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ5��ʵ��¥", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 684 - 6 && msg.x < 684 + 6 && msg.y>195 - 6 && msg.y < 195 + 6) {
								if (start1 != INF) {
									if (start1 == 0) { clickbig(388, 75); }
									else if (start1 == 1) { clickbig(568, 125); }
									else if (start1 == 2) { clickbig(634, 122); }
									else if (start1 == 3) { clickbig(251, 215); }
									else if (start1 == 4) { clickbig(463, 212); }
									else if (start1 == 5) { clickbig(614, 197); }
									else if (start1 == 6) { clickbig(684, 195); }
									else if (start1 == 7) { clickbig(326, 263); }
									else if (start1 == 8) { clickbig(569, 253); }
									else if (start1 == 9) { clickbig(205, 360); }
									else if (start1 == 10) { clickbig(571, 366); }
									else if (start1 == 11) { clickbig(571, 476); }
								}
									start1 = 6;
									clickbig1(684, 195);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ6����ͨѧ�������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 326 - 6 && msg.x < 326 + 6 && msg.y>263 - 6 && msg.y < 263 + 6) {
								if (start1 != INF) {
									if (start1 == 0) { clickbig(388, 75); }
									else if (start1 == 1) { clickbig(568, 125); }
									else if (start1 == 2) { clickbig(634, 122); }
									else if (start1 == 3) { clickbig(251, 215); }
									else if (start1 == 4) { clickbig(463, 212); }
									else if (start1 == 5) { clickbig(614, 197); }
									else if (start1 == 6) { clickbig(684, 195); }
									else if (start1 == 7) { clickbig(326, 263); }
									else if (start1 == 8) { clickbig(569, 253); }
									else if (start1 == 9) { clickbig(205, 360); }
									else if (start1 == 10) { clickbig(571, 366); }
									else if (start1 == 11) { clickbig(571, 476); }
								}
									start1 = 7;
									clickbig1(326, 263);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ7�����ƴ�¥", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 569 - 6 && msg.x < 569 + 6 && msg.y>253 - 6 && msg.y < 253 + 6) {
								if (start1 != INF) {
									if (start1 == 0) { clickbig(388, 75); }
									else if (start1 == 1) { clickbig(568, 125); }
									else if (start1 == 2) { clickbig(634, 122); }
									else if (start1 == 3) { clickbig(251, 215); }
									else if (start1 == 4) { clickbig(463, 212); }
									else if (start1 == 5) { clickbig(614, 197); }
									else if (start1 == 6) { clickbig(684, 195); }
									else if (start1 == 7) { clickbig(326, 263); }
									else if (start1 == 8) { clickbig(569, 253); }
									else if (start1 == 9) { clickbig(205, 360); }
									else if (start1 == 10) { clickbig(571, 366); }
									else if (start1 == 11) { clickbig(571, 476); }
								}
									start1 = 8;
									clickbig1(569, 253);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ8������ͼ���", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 205 - 6 && msg.x < 205 + 6 && msg.y>360 - 6 && msg.y < 360 + 6) {
								if (start1 != INF) {
									if (start1 == 0) { clickbig(388, 75); }
									else if (start1 == 1) { clickbig(568, 125); }
									else if (start1 == 2) { clickbig(634, 122); }
									else if (start1 == 3) { clickbig(251, 215); }
									else if (start1 == 4) { clickbig(463, 212); }
									else if (start1 == 5) { clickbig(614, 197); }
									else if (start1 == 6) { clickbig(684, 195); }
									else if (start1 == 7) { clickbig(326, 263); }
									else if (start1 == 8) { clickbig(569, 253); }
									else if (start1 == 9) { clickbig(205, 360); }
									else if (start1 == 10) { clickbig(571, 366); }
									else if (start1 == 11) { clickbig(571, 476); }
								}
									start1 = 9;
									clickbig1(205, 360);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ9����Ʋٳ�", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 571 - 6 && msg.x < 571 + 6 && msg.y>366 - 6 && msg.y < 366 + 6) {
								if (start1 != INF) {
									if (start1 == 0) { clickbig(388, 75); }
									else if (start1 == 1) { clickbig(568, 125); }
									else if (start1 == 2) { clickbig(634, 122); }
									else if (start1 == 3) { clickbig(251, 215); }
									else if (start1 == 4) { clickbig(463, 212); }
									else if (start1 == 5) { clickbig(614, 197); }
									else if (start1 == 6) { clickbig(684, 195); }
									else if (start1 == 7) { clickbig(326, 263); }
									else if (start1 == 8) { clickbig(569, 253); }
									else if (start1 == 9) { clickbig(205, 360); }
									else if (start1 == 10) { clickbig(571, 366); }
									else if (start1 == 11) { clickbig(571, 476); }
								}
									start1 = 10;
									clickbig1(571, 366);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ10���ܶ�����", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 571 - 6 && msg.x < 571 + 6 && msg.y>476 - 6 && msg.y < 476 + 6) {
								if (start1 != INF) {
									if (start1 == 0) { clickbig(388, 75); }
									else if (start1 == 1) { clickbig(568, 125); }
									else if (start1 == 2) { clickbig(634, 122); }
									else if (start1 == 3) { clickbig(251, 215); }
									else if (start1 == 4) { clickbig(463, 212); }
									else if (start1 == 5) { clickbig(614, 197); }
									else if (start1 == 6) { clickbig(684, 195); }
									else if (start1 == 7) { clickbig(326, 263); }
									else if (start1 == 8) { clickbig(569, 253); }
									else if (start1 == 9) { clickbig(205, 360); }
									else if (start1 == 10) { clickbig(571, 366); }
									else if (start1 == 11) { clickbig(571, 476); }
								}
									start1 = 11;
									clickbig1(571, 476);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ11��У��", "��ʾ", MB_OKCANCEL);
								}
							}
							break;
							//��ֹ�ڵ�ѡ��
							case WM_RBUTTONDOWN:
							{
								if (msg.x > 388 - 6 && msg.x < 388 + 6 && msg.y>75 - 6 && msg.y < 75 + 6) {
									if (end1 != INF) {
										if (end1 == 0) { clickbig(388, 75); }
										else if (end1 == 1) { clickbig(568, 125); }
										else if (end1 == 2) { clickbig(634, 122); }
										else if (end1 == 3) { clickbig(251, 215); }
										else if (end1 == 4) { clickbig(463, 212); }
										else if (end1 == 5) { clickbig(614, 197); }
										else if (end1 == 6) { clickbig(684, 195); }
										else if (end1 == 7) { clickbig(326, 263); }
										else if (end1 == 8) { clickbig(569, 253); }
										else if (end1 == 9) { clickbig(205, 360); }
										else if (end1 == 10) { clickbig(571, 366); }
										else if (end1 == 11) { clickbig(571, 476); }
									}
									end1 = 0;
									clickbig2(388, 75);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ0���Ŀ���������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 568 - 6 && msg.x < 568 + 6 && msg.y>125 - 6 && msg.y < 125 + 6) {
									if (end1 != INF) {
										if (end1 == 0) { clickbig(388, 75); }
										else if (end1 == 1) { clickbig(568, 125); }
										else if (end1 == 2) { clickbig(634, 122); }
										else if (end1 == 3) { clickbig(251, 215); }
										else if (end1 == 4) { clickbig(463, 212); }
										else if (end1 == 5) { clickbig(614, 197); }
										else if (end1 == 6) { clickbig(684, 195); }
										else if (end1 == 7) { clickbig(326, 263); }
										else if (end1 == 8) { clickbig(569, 253); }
										else if (end1 == 9) { clickbig(205, 360); }
										else if (end1 == 10) { clickbig(571, 366); }
										else if (end1 == 11) { clickbig(571, 476); }
									}
									end1 = 1;
									clickbig2(568, 125);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ1��������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 634 - 6 && msg.x < 634 + 6 && msg.y>122 - 6 && msg.y < 122 + 6) {
									if (end1 != INF) {
										if (end1 == 0) { clickbig(388, 75); }
										else if (end1 == 1) { clickbig(568, 125); }
										else if (end1 == 2) { clickbig(634, 122); }
										else if (end1 == 3) { clickbig(251, 215); }
										else if (end1 == 4) { clickbig(463, 212); }
										else if (end1 == 5) { clickbig(614, 197); }
										else if (end1 == 6) { clickbig(684, 195); }
										else if (end1 == 7) { clickbig(326, 263); }
										else if (end1 == 8) { clickbig(569, 253); }
										else if (end1 == 9) { clickbig(205, 360); }
										else if (end1 == 10) { clickbig(571, 366); }
										else if (end1 == 11) { clickbig(571, 476); }
									}
									end1 = 2;
									clickbig2(634, 122);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ2����������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 251 - 6 && msg.x < 251 + 6 && msg.y>215 - 6 && msg.y < 215 + 6) {
									if (end1 != INF) {
										if (end1 == 0) { clickbig(388, 75); }
										else if (end1 == 1) { clickbig(568, 125); }
										else if (end1 == 2) { clickbig(634, 122); }
										else if (end1 == 3) { clickbig(251, 215); }
										else if (end1 == 4) { clickbig(463, 212); }
										else if (end1 == 5) { clickbig(614, 197); }
										else if (end1 == 6) { clickbig(684, 195); }
										else if (end1 == 7) { clickbig(326, 263); }
										else if (end1 == 8) { clickbig(569, 253); }
										else if (end1 == 9) { clickbig(205, 360); }
										else if (end1 == 10) { clickbig(571, 366); }
										else if (end1 == 11) { clickbig(571, 476); }
									}
									end1 = 3;
									clickbig2(251, 215);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ3�������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 463 - 6 && msg.x < 463 + 6 && msg.y>212 - 6 && msg.y < 212 + 6) {
									if (end1 != INF) {
										if (end1 == 0) { clickbig(388, 75); }
										else if (end1 == 1) { clickbig(568, 125); }
										else if (end1 == 2) { clickbig(634, 122); }
										else if (end1 == 3) { clickbig(251, 215); }
										else if (end1 == 4) { clickbig(463, 212); }
										else if (end1 == 5) { clickbig(614, 197); }
										else if (end1 == 6) { clickbig(684, 195); }
										else if (end1 == 7) { clickbig(326, 263); }
										else if (end1 == 8) { clickbig(569, 253); }
										else if (end1 == 9) { clickbig(205, 360); }
										else if (end1 == 10) { clickbig(571, 366); }
										else if (end1 == 11) { clickbig(571, 476); }
									}
									end1 = 4;
									clickbig2(463, 212);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ4������¥", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 614 - 6 && msg.x < 614 + 6 && msg.y>197 - 6 && msg.y < 197 + 6) {
								if (end1 != INF) {
									if (end1 == 0) { clickbig(388, 75); }
									else if (end1 == 1) { clickbig(568, 125); }
									else if (end1 == 2) { clickbig(634, 122); }
									else if (end1 == 3) { clickbig(251, 215); }
									else if (end1 == 4) { clickbig(463, 212); }
									else if (end1 == 5) { clickbig(614, 197); }
									else if (end1 == 6) { clickbig(684, 195); }
									else if (end1 == 7) { clickbig(326, 263); }
									else if (end1 == 8) { clickbig(569, 253); }
									else if (end1 == 9) { clickbig(205, 360); }
									else if (end1 == 10) { clickbig(571, 366); }
									else if (end1 == 11) { clickbig(571, 476); }
								}
									end1 = 5;
									clickbig2(614, 197);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ5��ʵ��¥", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 684 - 6 && msg.x < 684 + 6 && msg.y>195 - 6 && msg.y < 195 + 6) {
								if (end1 != INF) {
									if (end1 == 0) { clickbig(388, 75); }
									else if (end1 == 1) { clickbig(568, 125); }
									else if (end1 == 2) { clickbig(634, 122); }
									else if (end1 == 3) { clickbig(251, 215); }
									else if (end1 == 4) { clickbig(463, 212); }
									else if (end1 == 5) { clickbig(614, 197); }
									else if (end1 == 6) { clickbig(684, 195); }
									else if (end1 == 7) { clickbig(326, 263); }
									else if (end1 == 8) { clickbig(569, 253); }
									else if (end1 == 9) { clickbig(205, 360); }
									else if (end1 == 10) { clickbig(571, 366); }
									else if (end1 == 11) { clickbig(571, 476); }
								}
									end1 = 6;
									clickbig2(684, 195);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ6����ͨѧ�������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 326 - 6 && msg.x < 326 + 6 && msg.y>263 - 6 && msg.y < 263 + 6) {
								if (end1 != INF) {
									if (end1 == 0) { clickbig(388, 75); }
									else if (end1 == 1) { clickbig(568, 125); }
									else if (end1 == 2) { clickbig(634, 122); }
									else if (end1 == 3) { clickbig(251, 215); }
									else if (end1 == 4) { clickbig(463, 212); }
									else if (end1 == 5) { clickbig(614, 197); }
									else if (end1 == 6) { clickbig(684, 195); }
									else if (end1 == 7) { clickbig(326, 263); }
									else if (end1 == 8) { clickbig(569, 253); }
									else if (end1 == 9) { clickbig(205, 360); }
									else if (end1 == 10) { clickbig(571, 366); }
									else if (end1 == 11) { clickbig(571, 476); }
								}
									end1 = 7;
									clickbig2(326, 263);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ7�����ƴ�¥", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 569 - 6 && msg.x < 569 + 6 && msg.y>253 - 6 && msg.y < 253 + 6) {
								if (end1 != INF) {
									if (end1 == 0) { clickbig(388, 75); }
									else if (end1 == 1) { clickbig(568, 125); }
									else if (end1 == 2) { clickbig(634, 122); }
									else if (end1 == 3) { clickbig(251, 215); }
									else if (end1 == 4) { clickbig(463, 212); }
									else if (end1 == 5) { clickbig(614, 197); }
									else if (end1 == 6) { clickbig(684, 195); }
									else if (end1 == 7) { clickbig(326, 263); }
									else if (end1 == 8) { clickbig(569, 253); }
									else if (end1 == 9) { clickbig(205, 360); }
									else if (end1 == 10) { clickbig(571, 366); }
									else if (end1 == 11) { clickbig(571, 476); }
								}
									end1 = 8;
									clickbig2(569, 253);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ8������ͼ���", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 205 - 6 && msg.x < 205 + 6 && msg.y>360 - 6 && msg.y < 360 + 6) {
								if (end1 != INF) {
									if (end1 == 0) { clickbig(388, 75); }
									else if (end1 == 1) { clickbig(568, 125); }
									else if (end1 == 2) { clickbig(634, 122); }
									else if (end1 == 3) { clickbig(251, 215); }
									else if (end1 == 4) { clickbig(463, 212); }
									else if (end1 == 5) { clickbig(614, 197); }
									else if (end1 == 6) { clickbig(684, 195); }
									else if (end1 == 7) { clickbig(326, 263); }
									else if (end1 == 8) { clickbig(569, 253); }
									else if (end1 == 9) { clickbig(205, 360); }
									else if (end1 == 10) { clickbig(571, 366); }
									else if (end1 == 11) { clickbig(571, 476); }
								}
									end1 = 9;
									clickbig2(205, 360);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ9����Ʋٳ�", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 571 - 6 && msg.x < 571 + 6 && msg.y>366 - 6 && msg.y < 366 + 6) {
								if (end1 != INF) {
									if (end1 == 0) { clickbig(388, 75); }
									else if (end1 == 1) { clickbig(568, 125); }
									else if (end1 == 2) { clickbig(634, 122); }
									else if (end1 == 3) { clickbig(251, 215); }
									else if (end1 == 4) { clickbig(463, 212); }
									else if (end1 == 5) { clickbig(614, 197); }
									else if (end1 == 6) { clickbig(684, 195); }
									else if (end1 == 7) { clickbig(326, 263); }
									else if (end1 == 8) { clickbig(569, 253); }
									else if (end1 == 9) { clickbig(205, 360); }
									else if (end1 == 10) { clickbig(571, 366); }
									else if (end1 == 11) { clickbig(571, 476); }
								}
									end1 = 10;
									clickbig2(571, 366);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ10���ܶ�����", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 571 - 6 && msg.x < 571 + 6 && msg.y>476 - 6 && msg.y < 476 + 6) {
								if (end1 != INF) {
									if (end1 == 0) { clickbig(388, 75); }
									else if (end1 == 1) { clickbig(568, 125); }
									else if (end1 == 2) { clickbig(634, 122); }
									else if (end1 == 3) { clickbig(251, 215); }
									else if (end1 == 4) { clickbig(463, 212); }
									else if (end1 == 5) { clickbig(614, 197); }
									else if (end1 == 6) { clickbig(684, 195); }
									else if (end1 == 7) { clickbig(326, 263); }
									else if (end1 == 8) { clickbig(569, 253); }
									else if (end1 == 9) { clickbig(205, 360); }
									else if (end1 == 10) { clickbig(571, 366); }
									else if (end1 == 11) { clickbig(571, 476); }
								}
									end1 = 11;
									clickbig2(571, 476);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ11��У��", "��ʾ", MB_OKCANCEL);
								}
							}
							}
						}
					}
				}

				//���ѡ�����̨У��
				else if (emsg.x > 500 && emsg.x < 700 && emsg.y>720 && emsg.y < 800) {
					initgraph(1200, 800, EW_SHOWCONSOLE);//����һ������,������xΪ800��yΪ1200
					setbkcolor(WHITE);
					cleardevice();
					IMAGE img;//����һ��img�Ķ���
					loadimage(&img, "./schoolmap2.jpg", 1000, 500);
					putimage(0, 0, &img);

					//���ð�ťλ��
					button1(100, 600, 250, 100);
					button2(500, 600, 250, 100);
					button5(900, 600, 250, 100);

					int start1 = INF; int end1 = INF;

					//0:187 100; 1:466 135; 2:610 145;3:820 144
								//4:598 251;5:722 238;6:216 351;7:512 416;
								//8:719 343;9:841 324
					clickbig(187, 100); clickbig(466, 135); clickbig(610, 145); clickbig(820, 144); clickbig(598, 251); clickbig(722, 238);
					clickbig(216, 351); clickbig(512, 416); clickbig(719, 343); clickbig(841, 324);
					ExMessage msg;
					while (true) {
						if (peekmessage(&msg, EM_MOUSE)) {
							switch (msg.message) {
							case WM_LBUTTONDOWN:
							{
								if (msg.x > 100 && msg.x < 350 && msg.y>600 && msg.y < 700) {
									//������ʾ������ʾ���·����
									HWND hnd1 = GetHWnd();


									//���·��������жϣ��Ƿ���ѡ����ʼλ�ú���ֹλ��
									//δѡ�񵯳���ʾ��
									if (end1 == INF || start1 == INF) {
										MessageBox(hnd1, "������������������㣬����Ҽ��������յ�", "��ʾ", MB_OKCANCEL);
									}
									//��ѡ�񵯳������
									else {
										if (start1 == end1) {
											MessageBox(hnd1, "�����յ㲻���غ�Ŷ", "��ʾ", MB_OKCANCEL);
										}
										else {
											HWND hnd1 = GetHWnd();
											MessageBox(hnd1, "���·��������ڿ���̨", "��ʾ", MB_OKCANCEL);
											schoolmap A(Nankai1);
											A.Dijkstra(start1, end1);
										}
									}
								}
								else if (msg.x > 500 && msg.x < 750 && msg.y>600 && msg.y < 700) {
									HWND hnd1 = GetHWnd();
									if (end1 == INF || start1 == INF) {
										MessageBox(hnd1, "������������������㣬����Ҽ��������յ�", "��ʾ", MB_OKCANCEL);
									}
									else {
										if (start1 == end1) {
											MessageBox(hnd1, "�����յ㲻���غ�Ŷ", "��ʾ", MB_OKCANCEL);
										}
										else{
											MessageBox(hnd1, "����·��������ڿ���̨", "��ʾ", MB_OKCANCEL);
											schoolmap A(Nankai1);
											vector<int>Visit(Nankai1[0].size(), 0);
											A.DFS(start1, end1, Visit);
										}
									}
								}
								else if (msg.x > 900 && msg.x < 1150 && msg.y>600 && msg.y < 700) {
									clickbig(187, 100); clickbig(466, 135); clickbig(610, 145); clickbig(820, 144); clickbig(598, 251); clickbig(722, 238);
									clickbig(216, 351); clickbig(512, 416); clickbig(719, 343); clickbig(841, 324);
									HWND hnd1 = GetHWnd();
									MessageBox(hnd1, "�����յ�������", "��ʾ", MB_OKCANCEL);
									start1 = INF; end1 = INF;
								}
								//��ʼ�ڵ��ѡ��
								if (msg.x > 187 - 6 && msg.x < 187 + 6 && msg.y>100 - 6 && msg.y < 100 + 6) {
									if (start1 != INF) {
										if(start1==0){ clickbig(187, 100); }
										else if(start1==1){ clickbig(466, 135); }
										else if(start1==2){ clickbig(610, 145); }
										else if(start1==3){ clickbig(820, 144); }
										else if(start1==4){ clickbig(598, 251); }
										else if(start1==5){ clickbig(722, 238); }
										else if(start1==6){ clickbig(216, 351); }
										else if(start1==7){ clickbig(512, 416); }
										else if(start1==8){ clickbig(719, 343); }
										else if(start1==9){ clickbig(841, 324); }
									}
									start1 = 0;
									clickbig1(187, 100);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ0��������Ԣ", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 466 - 6 && msg.x < 466 + 6 && msg.y>135 - 6 && msg.y < 135 + 6) {
									if (start1 != INF) {
										if (start1 == 0) { clickbig(187, 100); }
										else if (start1 == 1) { clickbig(466, 135); }
										else if (start1 == 2) { clickbig(610, 145); }
										else if (start1 == 3) { clickbig(820, 144); }
										else if (start1 == 4) { clickbig(598, 251); }
										else if (start1 == 5) { clickbig(722, 238); }
										else if (start1 == 6) { clickbig(216, 351); }
										else if (start1 == 7) { clickbig(512, 416); }
										else if (start1 == 8) { clickbig(719, 343); }
										else if (start1 == 9) { clickbig(841, 324); }
									}
									start1 = 1;
									clickbig1(466, 135);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ1��������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 610 - 6 && msg.x < 610 + 6 && msg.y>145 - 6 && msg.y < 145 + 6) {
									if (start1 != INF) {
										if (start1 == 0) { clickbig(187, 100); }
										else if (start1 == 1) { clickbig(466, 135); }
										else if (start1 == 2) { clickbig(610, 145); }
										else if (start1 == 3) { clickbig(820, 144); }
										else if (start1 == 4) { clickbig(598, 251); }
										else if (start1 == 5) { clickbig(722, 238); }
										else if (start1 == 6) { clickbig(216, 351); }
										else if (start1 == 7) { clickbig(512, 416); }
										else if (start1 == 8) { clickbig(719, 343); }
										else if (start1 == 9) { clickbig(841, 324); }
									}
									start1 = 2;
									clickbig1(610, 145);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ2����������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 820 - 6 && msg.x < 820 + 6 && msg.y>144 - 6 && msg.y < 144 + 6) {
									if (start1 != INF) {
										if (start1 == 0) { clickbig(187, 100); }
										else if (start1 == 1) { clickbig(466, 135); }
										else if (start1 == 2) { clickbig(610, 145); }
										else if (start1 == 3) { clickbig(820, 144); }
										else if (start1 == 4) { clickbig(598, 251); }
										else if (start1 == 5) { clickbig(722, 238); }
										else if (start1 == 6) { clickbig(216, 351); }
										else if (start1 == 7) { clickbig(512, 416); }
										else if (start1 == 8) { clickbig(719, 343); }
										else if (start1 == 9) { clickbig(841, 324); }
									}
									start1 = 3;
									clickbig1(820, 144);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ3������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 598 - 6 && msg.x < 598 + 6 && msg.y>251 - 6 && msg.y < 251 + 6) {
									if (start1 != INF) {
										if (start1 == 0) { clickbig(187, 100); }
										else if (start1 == 1) { clickbig(466, 135); }
										else if (start1 == 2) { clickbig(610, 145); }
										else if (start1 == 3) { clickbig(820, 144); }
										else if (start1 == 4) { clickbig(598, 251); }
										else if (start1 == 5) { clickbig(722, 238); }
										else if (start1 == 6) { clickbig(216, 351); }
										else if (start1 == 7) { clickbig(512, 416); }
										else if (start1 == 8) { clickbig(719, 343); }
										else if (start1 == 9) { clickbig(841, 324); }
									}
									start1 = 4;
									clickbig1(598, 251);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ4���¿���", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 722 - 6 && msg.x < 722 + 6 && msg.y>238 - 6 && msg.y < 238 + 6) {
									if (start1 != INF) {
										if (start1 == 0) { clickbig(187, 100); }
										else if (start1 == 1) { clickbig(466, 135); }
										else if (start1 == 2) { clickbig(610, 145); }
										else if (start1 == 3) { clickbig(820, 144); }
										else if (start1 == 4) { clickbig(598, 251); }
										else if (start1 == 5) { clickbig(722, 238); }
										else if (start1 == 6) { clickbig(216, 351); }
										else if (start1 == 7) { clickbig(512, 416); }
										else if (start1 == 8) { clickbig(719, 343); }
										else if (start1 == 9) { clickbig(841, 324); }
									}
									start1 = 5;
									clickbig1(722, 238);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ5�������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 216 - 6 && msg.x < 216 + 6 && msg.y>351 - 6 && msg.y < 351 + 6) {
								if (start1 != INF) {
									if (start1 == 0) { clickbig(187, 100); }
									else if (start1 == 1) { clickbig(466, 135); }
									else if (start1 == 2) { clickbig(610, 145); }
									else if (start1 == 3) { clickbig(820, 144); }
									else if (start1 == 4) { clickbig(598, 251); }
									else if (start1 == 5) { clickbig(722, 238); }
									else if (start1 == 6) { clickbig(216, 351); }
									else if (start1 == 7) { clickbig(512, 416); }
									else if (start1 == 8) { clickbig(719, 343); }
									else if (start1 == 9) { clickbig(841, 324); }
								}
									start1 = 6;
									clickbig1(216, 351);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ6�����ϴ�", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 512 - 6 && msg.x < 512 + 6 && msg.y>416 - 6 && msg.y < 416 + 6) {
								if (start1 != INF) {
									if (start1 == 0) { clickbig(187, 100); }
									else if (start1 == 1) { clickbig(466, 135); }
									else if (start1 == 2) { clickbig(610, 145); }
									else if (start1 == 3) { clickbig(820, 144); }
									else if (start1 == 4) { clickbig(598, 251); }
									else if (start1 == 5) { clickbig(722, 238); }
									else if (start1 == 6) { clickbig(216, 351); }
									else if (start1 == 7) { clickbig(512, 416); }
									else if (start1 == 8) { clickbig(719, 343); }
									else if (start1 == 9) { clickbig(841, 324); }
								}
									start1 = 7;
									clickbig1(512, 416);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ7��������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 719 - 6 && msg.x < 719 + 6 && msg.y>343 - 6 && msg.y < 343 + 6) {
								if (start1 != INF) {
									if (start1 == 0) { clickbig(187, 100); }
									else if (start1 == 1) { clickbig(466, 135); }
									else if (start1 == 2) { clickbig(610, 145); }
									else if (start1 == 3) { clickbig(820, 144); }
									else if (start1 == 4) { clickbig(598, 251); }
									else if (start1 == 5) { clickbig(722, 238); }
									else if (start1 == 6) { clickbig(216, 351); }
									else if (start1 == 7) { clickbig(512, 416); }
									else if (start1 == 8) { clickbig(719, 343); }
									else if (start1 == 9) { clickbig(841, 324); }
								}
									start1 = 8;
									clickbig1(719, 343);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ8�����Ļ�԰", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 841 - 6 && msg.x < 841 + 6 && msg.y>324 - 6 && msg.y < 324 + 6) {
								if (start1 != INF) {
									if (start1 == 0) { clickbig(187, 100); }
									else if (start1 == 1) { clickbig(466, 135); }
									else if (start1 == 2) { clickbig(610, 145); }
									else if (start1 == 3) { clickbig(820, 144); }
									else if (start1 == 4) { clickbig(598, 251); }
									else if (start1 == 5) { clickbig(722, 238); }
									else if (start1 == 6) { clickbig(216, 351); }
									else if (start1 == 7) { clickbig(512, 416); }
									else if (start1 == 8) { clickbig(719, 343); }
									else if (start1 == 9) { clickbig(841, 324); }
								}
									start1 = 9;
									clickbig1(841, 324);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "����ѱ�ѡΪ9������", "��ʾ", MB_OKCANCEL);
								}

								break;
								//��ֹ�ڵ�ѡ��
							case WM_RBUTTONDOWN:
							{
								if (msg.x > 187 - 6 && msg.x < 187 + 6 && msg.y>100 - 6 && msg.y < 100 + 6) {
									if (end1 != INF) {
										if (end1 == 0) { clickbig(187, 100); }
										else if (end1 == 1) { clickbig(466, 135); }
										else if (end1 == 2) { clickbig(610, 145); }
										else if (end1 == 3) { clickbig(820, 144); }
										else if (end1 == 4) { clickbig(598, 251); }
										else if (end1 == 5) { clickbig(722, 238); }
										else if (end1 == 6) { clickbig(216, 351); }
										else if (end1 == 7) { clickbig(512, 416); }
										else if (end1 == 8) { clickbig(719, 343); }
										else if (end1 == 9) { clickbig(841, 324); }
									}
									end1 = 0;
									clickbig2(187, 100);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ0��������Ԣ", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 466 - 6 && msg.x < 466 + 6 && msg.y>135 - 6 && msg.y < 135 + 6) {
									if (end1 != INF) {
										if (end1 == 0) { clickbig(187, 100); }
										else if (end1 == 1) { clickbig(466, 135); }
										else if (end1 == 2) { clickbig(610, 145); }
										else if (end1 == 3) { clickbig(820, 144); }
										else if (end1 == 4) { clickbig(598, 251); }
										else if (end1 == 5) { clickbig(722, 238); }
										else if (end1 == 6) { clickbig(216, 351); }
										else if (end1 == 7) { clickbig(512, 416); }
										else if (end1 == 8) { clickbig(719, 343); }
										else if (end1 == 9) { clickbig(841, 324); }
									}
									end1 = 1;
									clickbig2(466, 135);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ1��������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 610 - 6 && msg.x < 610 + 6 && msg.y>145 - 6 && msg.y < 145 + 6) {
									if (end1 != INF) {
										if (end1 == 0) { clickbig(187, 100); }
										else if (end1 == 1) { clickbig(466, 135); }
										else if (end1 == 2) { clickbig(610, 145); }
										else if (end1 == 3) { clickbig(820, 144); }
										else if (end1 == 4) { clickbig(598, 251); }
										else if (end1 == 5) { clickbig(722, 238); }
										else if (end1 == 6) { clickbig(216, 351); }
										else if (end1 == 7) { clickbig(512, 416); }
										else if (end1 == 8) { clickbig(719, 343); }
										else if (end1 == 9) { clickbig(841, 324); }
									}
									end1 = 2;
									clickbig2(610, 145);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ2����������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 820 - 6 && msg.x < 820 + 6 && msg.y>144 - 6 && msg.y < 144 + 6) {
									if (end1 != INF) {
										if (end1 == 0) { clickbig(187, 100); }
										else if (end1 == 1) { clickbig(466, 135); }
										else if (end1 == 2) { clickbig(610, 145); }
										else if (end1 == 3) { clickbig(820, 144); }
										else if (end1 == 4) { clickbig(598, 251); }
										else if (end1 == 5) { clickbig(722, 238); }
										else if (end1 == 6) { clickbig(216, 351); }
										else if (end1 == 7) { clickbig(512, 416); }
										else if (end1 == 8) { clickbig(719, 343); }
										else if (end1 == 9) { clickbig(841, 324); }
									}
									end1 = 3;
									clickbig2(820, 144);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ3������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 598 - 6 && msg.x < 598 + 6 && msg.y>251 - 6 && msg.y < 251 + 6) {
									if (end1 != INF) {
										if (end1 == 0) { clickbig(187, 100); }
										else if (end1 == 1) { clickbig(466, 135); }
										else if (end1 == 2) { clickbig(610, 145); }
										else if (end1 == 3) { clickbig(820, 144); }
										else if (end1 == 4) { clickbig(598, 251); }
										else if (end1 == 5) { clickbig(722, 238); }
										else if (end1 == 6) { clickbig(216, 351); }
										else if (end1 == 7) { clickbig(512, 416); }
										else if (end1 == 8) { clickbig(719, 343); }
										else if (end1 == 9) { clickbig(841, 324); }
									}
									end1 = 4;
									clickbig2(598, 251);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ4���¿���", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 722 - 6 && msg.x < 722 + 6 && msg.y>238 - 6 && msg.y < 238 + 6) {
									if (end1 != INF) {
										if (end1 == 0) { clickbig(187, 100); }
										else if (end1 == 1) { clickbig(466, 135); }
										else if (end1 == 2) { clickbig(610, 145); }
										else if (end1 == 3) { clickbig(820, 144); }
										else if (end1 == 4) { clickbig(598, 251); }
										else if (end1 == 5) { clickbig(722, 238); }
										else if (end1 == 6) { clickbig(216, 351); }
										else if (end1 == 7) { clickbig(512, 416); }
										else if (end1 == 8) { clickbig(719, 343); }
										else if (end1 == 9) { clickbig(841, 324); }
									}
									end1 = 5;
									clickbig2(722, 238);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ5�������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 216 - 6 && msg.x < 216 + 6 && msg.y>351 - 6 && msg.y < 351 + 6) {
								if (end1 != INF) {
									if (end1 == 0) { clickbig(187, 100); }
									else if (end1 == 1) { clickbig(466, 135); }
									else if (end1 == 2) { clickbig(610, 145); }
									else if (end1 == 3) { clickbig(820, 144); }
									else if (end1 == 4) { clickbig(598, 251); }
									else if (end1 == 5) { clickbig(722, 238); }
									else if (end1 == 6) { clickbig(216, 351); }
									else if (end1 == 7) { clickbig(512, 416); }
									else if (end1 == 8) { clickbig(719, 343); }
									else if (end1 == 9) { clickbig(841, 324); }
								}
									end1 = 6;
									clickbig2(216, 351);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ6�����ϴ�", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 512 - 6 && msg.x < 512 + 6 && msg.y>416 - 6 && msg.y < 416 + 6) {
								if (end1 != INF) {
									if (end1 == 0) { clickbig(187, 100); }
									else if (end1 == 1) { clickbig(466, 135); }
									else if (end1 == 2) { clickbig(610, 145); }
									else if (end1 == 3) { clickbig(820, 144); }
									else if (end1 == 4) { clickbig(598, 251); }
									else if (end1 == 5) { clickbig(722, 238); }
									else if (end1 == 6) { clickbig(216, 351); }
									else if (end1 == 7) { clickbig(512, 416); }
									else if (end1 == 8) { clickbig(719, 343); }
									else if (end1 == 9) { clickbig(841, 324); }
								}
									end1 = 7;
									clickbig2(512, 416);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ7��������", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 719 - 6 && msg.x < 719 + 6 && msg.y>343 - 6 && msg.y < 343 + 6) {
								if (end1 != INF) {
									if (end1 == 0) { clickbig(187, 100); }
									else if (end1 == 1) { clickbig(466, 135); }
									else if (end1 == 2) { clickbig(610, 145); }
									else if (end1 == 3) { clickbig(820, 144); }
									else if (end1 == 4) { clickbig(598, 251); }
									else if (end1 == 5) { clickbig(722, 238); }
									else if (end1 == 6) { clickbig(216, 351); }
									else if (end1 == 7) { clickbig(512, 416); }
									else if (end1 == 8) { clickbig(719, 343); }
									else if (end1 == 9) { clickbig(841, 324); }
								}
									end1 = 8;
									clickbig2(719, 343);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ8�����Ļ�԰", "��ʾ", MB_OKCANCEL);
								}
								else if (msg.x > 841 - 6 && msg.x < 841 + 6 && msg.y>324 - 6 && msg.y < 324 + 6) {
								if (end1 != INF) {
									if (end1 == 0) { clickbig(187, 100); }
									else if (end1 == 1) { clickbig(466, 135); }
									else if (end1 == 2) { clickbig(610, 145); }
									else if (end1 == 3) { clickbig(820, 144); }
									else if (end1 == 4) { clickbig(598, 251); }
									else if (end1 == 5) { clickbig(722, 238); }
									else if (end1 == 6) { clickbig(216, 351); }
									else if (end1 == 7) { clickbig(512, 416); }
									else if (end1 == 8) { clickbig(719, 343); }
									else if (end1 == 9) { clickbig(841, 324); }
								}
									end1 = 9;
									clickbig2(841, 324);
									HWND hnd2 = GetHWnd();
									MessageBox(hnd2, "�յ��ѱ�ѡΪ9������", "��ʾ", MB_OKCANCEL);
								}
							}
							}
							}
						}

					}
				}
			}
		}
	}
}

	