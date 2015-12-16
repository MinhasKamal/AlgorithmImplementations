/************************************************************************************************
* Developer: Minhas Kamal(BSSE-0509, IIT, DU)													*
* Date: Sep-2014																				*
*************************************************************************************************/

package thread.utilClasses;

public class Result {
	public String jobName;
	public char symbol;
	public float waitingTime;
	
	public Result() {
		this.jobName = "EMPTY";
		this.symbol = ' ';
		waitingTime = -1;
	}
	
	public Result(String jobName, char symbol){
		this.jobName = jobName;
		this.symbol = symbol;
		waitingTime = -1;
	}
	
	public Result(String jobName, char symbol, float waitingTime){
		this.jobName = jobName;
		this.symbol = symbol;
		this.waitingTime = waitingTime;
	}
}
