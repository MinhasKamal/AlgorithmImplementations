/**
* Name: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 04-Dec-2014
**/

package cigaretteSmokersProblem;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

public class Agent {
	private Smoker[] smokers;
	
	public Agent(Smoker[] smokers) {
		this.smokers = smokers;
	}
	
	public Queue<Character> start(int time){
		Queue<Character> symbols = new LinkedList<Character>();
		
		int i=0;
		while(i<time){
			int rand = random(smokers.length);
			
			if(rand<smokers.length){
				for(int j=0; j<smokers[rand].smokingTime; j+=10, i+=10){
					symbols.add(smokers[rand].ingredient);
					System.out.println(smokers[rand].ingredient);
				}
			}else{
				symbols.add('0');
				System.out.println("0");
				i += 10;
			}
		}
		
		return symbols;
	}
	
	private int random(int length){
		int i=0;
		
		i = new Random().nextInt(length*2);
		//System.out.println("OK :"+i);
		
		return i;
	}
}
