/**
* Name: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 04-Dec-2014
**/

package cigaretteSmokersProblem;

import java.util.Queue;

public class CigaretteSmokersProblemMain {
	
	public CigaretteSmokersProblemMain() {
		Smoker[] smokers = new Smoker[3];
		smokers[0] = new Smoker('1', 100);
		smokers[1] = new Smoker('2', 150);
		smokers[2] = new Smoker('3', 80);

		Agent agent = new Agent(smokers);
		
		Queue<Character> symbols = agent.start(800);
		
		new Graph(symbols).setVisible(true);
	}
	
	
	public static void main(String[] args) {
		new CigaretteSmokersProblemMain();
	}
}
