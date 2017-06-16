// Class Description:   
//         this class can make time go away in every second
//		   if time is up it will make model can't do any thing
//			and display you lose

package final_project;

import javafx.concurrent.Task;

public class MyTask extends Task<Void>{
	int total = 100;
	static int i;
	static boolean win;
	public void start(){
		i = 0;
		win = false;
	}
	protected Void call(){
		updateTitle("Simple Task Example");
        updateProgress(0, total);
        win = true;
        for (i = 0;;i++) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {}
            if(i < 0)i = 0;
        	if(i <= 100){
        		updateTitle("Simple Task Example(" + (total - i) + ")");         
        		updateProgress(i, total);
        	}
        	else {
        		updateTitle("you lose");
        		Model.move = false;
        	}
        	if(win){
        		i--;
        	}
        }
	}
}