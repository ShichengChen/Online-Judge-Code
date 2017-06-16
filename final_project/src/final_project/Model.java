// Class Description:   
//                   this most important class
//					 it have lots of data about link game such as begin place
//					 how big about tile and the number of the tiles

//					every times you want to start a game it will display a new
//					arrange about tiles

//					when you click on this model class (which is inherit from AnchorPane)
//					this class can calculate whether tile is selected and whether two tiles
//					can disappear 
//					and it can give the line to display which two tile will disappear


package final_project;


import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import javafx.animation.FadeTransition;
import javafx.animation.FadeTransitionBuilder;
import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.RectangleBuilder;
import javafx.util.Duration;

@SuppressWarnings("deprecation")
public class Model extends AnchorPane{
	int [][] beg = new int [3][3];
	static int times,level;
	int row,column;
	int [][] num = new int [3][3];
	Tile [][] tile = new Tile [20][20];
	MyStruct [][][] pre = new MyStruct [20][20][4];
	int [][] map = new int[20][20];
	static boolean move;
	List<Integer>list;
	AnchorPane root = new AnchorPane();
	Model(int l){
		move = true;
		level = l;
		num[0][0] = 7;num[0][1] = 6;num[0][2] = 80;
		// x -> 0 | y -> 1
		num[1][0]= 8;num[1][1] = 7;num[1][2] = 70;
		num[2][0] = 10;num[2][1] = 7;num[2][2] = 65;
		beg[0][0] = 150;beg[0][1] = 45;
		beg[1][0] = 150;beg[1][1] = 45;
		beg[2][0] = 100;beg[2][1] = 45;
		times = 0;
		list = new ArrayList<Integer>();
		int dif[] = {12,13,14};
		for(int i = 0;i < num[level][0] * num[level][1] / 2;i++){
			list.add(i % dif[level] + 1);
			list.add(i % dif[level] + 1);
		}
		Collections.shuffle(list);
		Rectangle cur = RectangleBuilder.create().
				layoutX(800).
				layoutY(600).
				build();
		root.getChildren().addAll(cur);
		this.getChildren().add(root);
	}
	// build a new model it will random select some tile disappear
	public void init_level(){
		 for(int i = 0;i < 20;i ++)
			for(int j = 0;j < 20;j++){
				if(j <= num[level][0] + 1 && i <= num[level][1] + 1)
					 map[i][j] = 0;
				else map[i][j] = -1;
			}
		 int cnt = 0;
		 for(int i = 1;i <= num[level][1];i++)
			 for(int j = 1;j <= num[level][0];j++){
				// x -> 0 | y -> 1
				// j -> x | i -> y
				 int x = beg[level][0] + (j - 1) * num[level][2];
				 int y = beg[level][1] + (i - 1) * num[level][2];
				 int rand = list.get(cnt++);
				 tile[i][j] = new Tile(x,y,num[level][2],rand);
				 tile[i][j].setOpacity(0.8);
				 root.getChildren().addAll(tile[i][j]);
				 map[i][j] = rand;
			 }
		 root.addEventHandler(MouseEvent.MOUSE_CLICKED, new ClickListener());
	}
	// when you clicked on this root ,it will response to you action
	public void clear(){
		root.getChildren().clear();
	}
	// this function can clear all tiles on the model
	
	
	// this function will response to you action
	public class ClickListener implements EventHandler<MouseEvent> 
	{

		int[] have = new int[6];
		boolean flag = false;
		public void handle(MouseEvent actEvt)
		{
			int yth = (int)((actEvt.getY() - beg[level][1]) / num[level][2]);
			int xth = (int)((actEvt.getX() - beg[level][0]) / num[level][2]);
			if(xth <= num[level][0] && yth <= num[level][1] && actEvt.getY() >= beg[level][1] && 
					actEvt.getX() >= beg[level][0] && map[++yth][++xth] > 0 && move){
				tile[yth][xth].set_color(1);
				if(flag == false){
					have[0] = xth;
					have[1] = yth;
					flag = true;
				}
				else{
					if(check(have[0],have[1],xth,yth)){
						FadeTransition fd1 = FadeTransitionBuilder.create()
								.node(tile[have[1]][have[0]])
								.duration(new Duration(1000.0))
								.fromValue(1)
								.toValue(0)
								.build();
						FadeTransition fd2 = FadeTransitionBuilder.create()
								.duration(new Duration(1000.0))
								.node(tile[yth][xth])
								.fromValue(1)
								.toValue(0)
								.build();
						fd2.play();
						fd1.play();
						map[yth][xth] = map[have[1]][have[0]] = 0;
						flag = false;
						times += 2;
					}
					else{
						tile[have[1]][have[0]].set_color(0);
						have[0] = xth;
						have[1] = yth;
					}
				}
			}
			else if(move){
				tile[have[1]][have[0]].set_color(0);
				flag = false;
			}
		}
	}
	//this function can check whether or not two tiles can disappear
	public boolean check(int x1,int y1,int x2,int y2){
		if((x1 == x2 && y1 == y2) || (map[y1][x1] != map[y2][x2]))
			return false;
		return spfa(x1,y1,x2,y2);
	}
	// this function can use bellman-ford algorithm to judge whether these tow
	// tile can disappear
	public boolean spfa(int x1,int y1,int x2,int y2){
		int [][][] dp = new int[20][20][20];
		boolean [][][] inque = new boolean [20][20][4];
		
		int dir[][] = {{0,1,0},{1,0,1},{0,-1,2},{-1,0,3}};
		for(int i = 0;i < 20;i++)
			for(int j = 0;j < 20;j++)
				for(int k = 0;k < 4;k++){
					dp[i][j][k] = 100000;
					inque[i][j][k] = false;
				}
		dp[y1][x1][0] = dp[y1][x1][1] = dp[y1][x1][2] = dp[y1][x1][3] = 0;
		inque[y1][x1][0] = inque[y1][x1][1] = inque[y1][x1][2] = inque[y1][x1][3] = true;
		Queue<MyStruct> que = new LinkedList<MyStruct>(); 
		que.add(new MyStruct(x1,y1,0));
		que.add(new MyStruct(x1,y1,1));
		que.add(new MyStruct(x1,y1,2));  
		que.add(new MyStruct(x1,y1,3));
		while(!que.isEmpty()){
			MyStruct cur = que.poll();
			inque[cur.y][cur.x][cur.w] = false;
			for(int i = 0;i < 4;i++){
				int x = cur.x + dir[i][0],y = cur.y + dir[i][1],add;
				if(cur.w != i)add = 1;
				else add = 0;
				if(x == x2 && y == y2 || (x >= 0 && y >= 0 && map[y][x] == 0)){
					if(dp[y][x][i] > dp[cur.y][cur.x][cur.w] + add){
						dp[y][x][i] = dp[cur.y][cur.x][cur.w] + add;
						pre[y][x][i] = cur;
						if(inque[y][x][i] == false){
							inque[y][x][i] = true;
							que.add(new MyStruct(x,y,i));
						}
					}
				}
			}
		}
		int minn = 1000,w2 = 1;
		for(int i = 0;i < 4;i++)
			if(dp[y2][x2][i] < minn){
				w2 = i;
				minn = dp[y2][x2][i];
			}
		if(minn <= 2){
			MyTask.i--;
			createline(x1,y1,x2,y2,w2);
			return true;
		}
		else return false;
	}
	// this function can create lines in the best way using the result 
	// of the spfa function
	public void createline(int x1,int y1,int x2,int y2,int w2){
		int x,y,w;
		do{
			Line line = new Line();
			line.setStartX((x2 - 0.5) * num[level][2] + beg[level][0]);
			line.setStartY((y2 - 0.5) * num[level][2] + beg[level][1]);
			x = pre[y2][x2][w2].x;
			y = pre[y2][x2][w2].y;
			w = pre[y2][x2][w2].w;
			line.setEndX((x - 0.5) * num[level][2] + beg[level][0]);
			line.setEndY((y - 0.5) * num[level][2] + beg[level][1]);
			root.getChildren().addAll(line);
			FadeTransition ft = FadeTransitionBuilder.create()
					.duration(new Duration(1000.0))
					.node(line)
					.fromValue(1)
					.toValue(0)
					.build();
			ft.play();
			y2 = y;
			x2 = x;
			w2 = w;
		}while(x != x1 || y != y1);
	}
}

