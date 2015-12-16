/************************************************************************************************
* Developer: Minhas Kamal(BSSE-0509, IIT, DU)													*
* Date: Sep-2014																				*
*************************************************************************************************/

package thread.utilClasses;

public class Process {
	public String jobName;
	public int arrivalTime;
	public int cpuTime;
	public int priority;
	public char symbol;
	
	public Process(){
		this.jobName = "";
		this.arrivalTime = 0;
		this.cpuTime = 0;
		this.priority = 1;
		this.symbol = '0';
	}
	
	public Process(String jobName, int arrivalTime, int cpuTime, char symbol){
		this.jobName = jobName;
		this.arrivalTime = arrivalTime;
		this.cpuTime = cpuTime;
		this.priority = 1;
		this.symbol = symbol;
	}
	
	public Process(String jobName, int arrivalTime, int cpuTime, int priority, char symbol){
		this.jobName = jobName;
		this.arrivalTime = arrivalTime;
		this.cpuTime = cpuTime;
		this.priority = priority;
		this.symbol = symbol;
	}
	
}
