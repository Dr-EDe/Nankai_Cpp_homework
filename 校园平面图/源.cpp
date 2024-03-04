#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<graphics.h>
#include<easyx.h>

using namespace std;
const int INF = 99999999;
//每次要使用功能时都初始化一次schoolmap对象；
class schoolmap{
private:
	vector<vector<int>>Nankaigraph;//邻接矩阵
	vector<int>dist;//保存最短路径长度的向量
	vector<int>path;//记录最短路径走法的向量
	vector<int>q;//记录所有路径走法的向量
	int sum;//记录路径条数

public:
	//判断是否是孤立的点的函数
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
	//最短路径函数
	void Dijkstra(int start, int goal) {
		cout<<endl;
		//考虑鲁棒性
		//如果两者有一个是孤立的点则输出
		if (if_isloated(start) || if_isloated(goal)) {
			cout << start << "=>" << goal << "无路径" << endl;
			return;
		}
		
		//普遍情况
		int n = Nankaigraph[0].size();//n代表所有的结点数
		vector<int>dist(n, 0);
		vector<int>visit1(n, 0);
		vector<int>path(n, -1);//分别进行初始化
		for (int i = 0; i < n; i++) {
			dist[i] = Nankaigraph[start][i];//初始化dist数组为最初图中的长度
		}
		visit1[start] = 1;//将初始节点标记为已使用
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
		while (path[j] != -1)      //如果j有中途节点
		{
			q1.push(j);          //将j压入堆
			j = path[j];          //将j的前个中途节点赋给j
		}
		q1.push(j);
		
		printf("%d=>%d, 最短路径长度为:%d, 最短路径为: %d ", start, goal, dist[goal], start);
		while (!q1.empty())       //先进后出,获得正序
		{
			printf("%d ", q1.top());//打印堆的头节点
			q1.pop();     //将堆的头节点弹出
		}
		printf("\n");
	}
	//所有路径函数
	void DFS(int start, int goal, vector<int>visit) {
		if (if_isloated(start) || if_isloated(goal)) {
			cout << start << "=>" << goal << "无路径" << endl;
			return;
		}
		visit.at(start) = 1;
		q.push_back(start);
		if (goal == start) {
			sum++;
			cout << endl << "第" << sum << "条路径为：" << q.at(0);
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
		return;//退出该层递归；
	}
	//构造函数
	schoolmap (vector<vector<int>>& Graph) {
		Nankaigraph = Graph;
		sum = 0;
	}
};

//绘制最短路径按钮函数
void button1(int x, int y, int w, int h) {
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(126, 12, 110));//南开紫专属
	fillroundrect(x, y, x + w, y + h, 30,30);
	
	//将文字置中
	settextstyle(30, 0, "黑体");
	int tx = x + (w - textwidth("最短路径"))/2;
	int ty = y + (h - textheight("最短路径")) / 2;
	settextcolor(BLACK);
	outtextxy(tx, ty, "最短路径");
}

//绘制所有路径按钮函数
void button2(int x, int y, int w, int h) {
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(126, 12, 110));//南开紫专属
	fillroundrect(x, y, x + w, y + h, 30, 30);

	//将文字置中
	settextstyle(30, 0, "黑体");
	int tx = x + (w - textwidth("所有路径")) / 2;
	int ty = y + (h - textheight("所有路径")) / 2;
	settextcolor(BLACK);
	outtextxy(tx, ty, "所有路径");
}

//绘制津南校区按钮函数
void button3(int x, int y, int w, int h) {
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(126, 12, 110));//南开紫专属
	fillroundrect(x, y, x + w, y + h, 30, 30);

	//将文字置中
	settextstyle(30, 0, "津南校区");
	int tx = x + (w - textwidth("津南校区")) / 2;
	int ty = y + (h - textheight("津南校区")) / 2;
	settextcolor(BLACK);
	outtextxy(tx, ty, "津南校区");
}

//绘制八里台校区按钮函数
void button4(int x, int y, int w, int h) {
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(126, 12, 110));//南开紫专属
	fillroundrect(x, y, x + w, y + h, 30, 30);

	//将文字置中
	settextstyle(30, 0, "黑体");
	int tx = x + (w - textwidth("八里台校区")) / 2;
	int ty = y + (h - textheight("八里台校区")) / 2;
	settextcolor(BLACK);
	outtextxy(tx, ty, "八里台校区");
}

//绘制清除按钮函数
void button5(int x, int y, int w, int h) {
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(126, 12, 110));//南开紫专属
	fillroundrect(x, y, x + w, y + h, 30, 30);

	//将文字置中
	settextstyle(30, 0, "黑体");
	int tx = x + (w - textwidth("清除")) / 2;
	int ty = y + (h - textheight("清除")) / 2;
	settextcolor(BLACK);
	outtextxy(tx, ty, "清除");
}



//绘制点的函数
void clickbig(int x,int y) {
	setfillcolor(BLACK);
	solidcircle(x, y, 9);
}

//点击起点变为绿色
void clickbig1(int x, int y) {
	setfillcolor(GREEN);
	solidcircle(x, y, 9);
}

//点击终点变为红色
void clickbig2(int x, int y) {
	setfillcolor(RED);
	solidcircle(x, y, 9);
}

//主函数
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
	Nankai[7][9] = 250; Nankai[8][10] = 140; Nankai[9][10] = 482;//此数据含孤立点11，可验证程序鲁棒性
	
	
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (j > i) { Nankai[j][i] = Nankai[i][j]; }
		}
	}//对津南地区地图邻接矩阵初始化完成


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
	//对八里台地区地图邻接矩阵初始化完成

	//创建初始界面
	initgraph(1200, 900, EW_NOMINIMIZE);//创建一个窗口,设置其x为800，y为1200
	setbkcolor(WHITE);
	cleardevice();
	IMAGE imag;
	loadimage(&imag, "./nankai.jpg", 400, 400);
	putimage(400, 0, &imag);
	settextstyle(50, 0, "黑体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(400, 400, "欢迎来到南开大学");
	outtextxy(400, 500, "请选择你要去的校区");
	button3(500, 600, 200, 80);
	button4(500, 720, 200, 80);

	ExMessage emsg;
	while (true) {
		ExMessage emsg;
		if (peekmessage(&emsg, EM_MOUSE)) {
			switch (emsg.message) {
			case  WM_LBUTTONDOWN:

				//如果选择津南校区
				if (emsg.x > 500 && emsg.x < 700 && emsg.y>600 && emsg.y < 680) {
					initgraph(1200, 800, EW_SHOWCONSOLE);//创建一个窗口,设置其x为800，y为1200
					setbkcolor(WHITE);
					cleardevice();
					IMAGE img;//定义一个img的对象
					loadimage(&img, "./schoolmap1.jpg", 800, 500);
					putimage(0, 0, &img);

					clickbig(388, 75); clickbig(568, 125); clickbig(634, 122); clickbig(251, 215); clickbig(463, 212); clickbig(614, 197);
					clickbig(684, 195); clickbig(326, 263); clickbig(569, 253); clickbig(205, 360); clickbig(571, 366); clickbig(571, 476);
						
					//按钮的放置
					button1(900, 100, 150, 80);
					button2(900, 300, 150, 80);
					button5(900, 500, 150, 80);
					int start1 = INF; int end1 = INF;
					ExMessage msg;
					while (true) {
						if (peekmessage(&msg, EM_MOUSE)) {
							switch (msg.message) {
								//点的坐标 0：388 75；1：568 125；2：634 122；
									 //3：251 215；4：463 212；5：614 197；6：684 195；7：326 263；
									 //8：569 253；9：205 360；10：571 366；11：571 476
							case WM_LBUTTONDOWN:
							{
								if (msg.x > 900 && msg.x < 1050 && msg.y>100 && msg.y < 180) {
									//弹出提示框：请显示最短路径；
									HWND hnd1 = GetHWnd();


									//最短路径输出的判断，是否已选择起始位置和终止位置
									//未选择弹出提示框
									if (end1 == INF || start1 == INF) {
										MessageBox(hnd1, "请用鼠标左键点击你的起点，鼠标右键点击你的终点", "提示", MB_OKCANCEL);
									}
									//已选择弹出结果框
									else {
										if (end1 == start1) {
											MessageBox(hnd1, "起点和终点不能重合哦", "提示", MB_OKCANCEL);
										}
										else {
											HWND hnd1 = GetHWnd();
											MessageBox(hnd1, "最短路径已输出在控制台", "提示", MB_OKCANCEL);
											schoolmap A(Nankai);
											A.Dijkstra(start1, end1);
										}
									}	
								}
								else if (msg.x > 900 && msg.x < 1050 && msg.y>300 && msg.y < 380) {
									HWND hnd1 = GetHWnd();
									if (end1 == INF || start1 == INF) {
										MessageBox(hnd1, "请用鼠标左键点击你的起点，鼠标右键点击你的终点", "提示", MB_OKCANCEL);
									}
									else {
										if (start1 == end1) {
											MessageBox(hnd1, "起点和终点不能重合哦", "提示", MB_OKCANCEL);
										}
										else{
											HWND hnd1 = GetHWnd();
											MessageBox(hnd1, "所有路径已输出在控制台", "提示", MB_OKCANCEL);
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
									MessageBox(hnd1, "起点和终点已重置", "提示", MB_OKCANCEL);
									start1 = INF; end1 = INF;
								}
								//起始节点的选择
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
									MessageBox(hnd2, "起点已被选为0：文科生活组团", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为1：体育馆", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为2：主体育场", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为3：马蹄湖", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为4：公教楼", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为5：实验楼", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为6：大通学生活动中心", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为7：理工科大楼", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为8：中心图书馆", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为9：理科操场", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为10：周恩来像", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为11：校门", "提示", MB_OKCANCEL);
								}
							}
							break;
							//终止节点选择
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
									MessageBox(hnd2, "终点已被选为0：文科生活组团", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为1：体育馆", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为2：主体育场", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为3：马蹄湖", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为4：公教楼", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为5：实验楼", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为6：大通学生活动中心", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为7：理工科大楼", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为8：中心图书馆", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为9：理科操场", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为10：周恩来像", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为11：校门", "提示", MB_OKCANCEL);
								}
							}
							}
						}
					}
				}

				//如果选择八里台校区
				else if (emsg.x > 500 && emsg.x < 700 && emsg.y>720 && emsg.y < 800) {
					initgraph(1200, 800, EW_SHOWCONSOLE);//创建一个窗口,设置其x为800，y为1200
					setbkcolor(WHITE);
					cleardevice();
					IMAGE img;//定义一个img的对象
					loadimage(&img, "./schoolmap2.jpg", 1000, 500);
					putimage(0, 0, &img);

					//放置按钮位置
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
									//弹出提示框：请显示最短路径；
									HWND hnd1 = GetHWnd();


									//最短路径输出的判断，是否已选择起始位置和终止位置
									//未选择弹出提示框
									if (end1 == INF || start1 == INF) {
										MessageBox(hnd1, "请用鼠标左键点击你的起点，鼠标右键点击你的终点", "提示", MB_OKCANCEL);
									}
									//已选择弹出结果框
									else {
										if (start1 == end1) {
											MessageBox(hnd1, "起点和终点不能重合哦", "提示", MB_OKCANCEL);
										}
										else {
											HWND hnd1 = GetHWnd();
											MessageBox(hnd1, "最短路径已输出在控制台", "提示", MB_OKCANCEL);
											schoolmap A(Nankai1);
											A.Dijkstra(start1, end1);
										}
									}
								}
								else if (msg.x > 500 && msg.x < 750 && msg.y>600 && msg.y < 700) {
									HWND hnd1 = GetHWnd();
									if (end1 == INF || start1 == INF) {
										MessageBox(hnd1, "请用鼠标左键点击你的起点，鼠标右键点击你的终点", "提示", MB_OKCANCEL);
									}
									else {
										if (start1 == end1) {
											MessageBox(hnd1, "起点和终点不能重合哦", "提示", MB_OKCANCEL);
										}
										else{
											MessageBox(hnd1, "所有路径已输出在控制台", "提示", MB_OKCANCEL);
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
									MessageBox(hnd1, "起点和终点已重置", "提示", MB_OKCANCEL);
									start1 = INF; end1 = INF;
								}
								//起始节点的选择
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
									MessageBox(hnd2, "起点已被选为0：西区公寓", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为1：体育场", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为2：新体育场", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为3：北村", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为4：新开湖", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为5：马蹄湖", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为6：西南村", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为7：总理像", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为8：中心花园", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "起点已被选为9：东村", "提示", MB_OKCANCEL);
								}

								break;
								//终止节点选择
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
									MessageBox(hnd2, "终点已被选为0：西区公寓", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为1：体育场", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为2：新体育场", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为3：北村", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为4：新开湖", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为5：马蹄湖", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为6：西南村", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为7：总理像", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为8：中心花园", "提示", MB_OKCANCEL);
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
									MessageBox(hnd2, "终点已被选为9：东村", "提示", MB_OKCANCEL);
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

	