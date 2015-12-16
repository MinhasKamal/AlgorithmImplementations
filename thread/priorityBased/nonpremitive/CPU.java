/************************************************************************************************
* Developer: Minhas Kamal(BSSE-0509, IIT, DU)													*
* Date: Sep-2014																				*
*************************************************************************************************/

package thread.priorityBased.nonpremitive;

import java.util.LinkedList;
import java.util.Queue;

import thread.utilClasses.Process;
import thread.utilClasses.Result;

public class CPU {
	private final int CPU_CYCLE_TIME = 100;
	
	public int time;
	public Queue<Process> waitingQueue = new LinkedList<Process>();
	public Queue<Result> result = new LinkedList<Result>();

	
	public Queue<Result> runProcess(Queue<Process> processes){

		while(!processes.isEmpty() || !waitingQueue.isEmpty()){
			
			while(!processes.isEmpty() && processes.element().arrivalTime<=time){
				waitingQueue.add(processes.peek());
				processes.remove();
			}
			
			
			//run the program
			if(!waitingQueue.isEmpty()){
				order(waitingQueue);
				
				waitingQueue.element().cpuTime -= CPU_CYCLE_TIME;
				waitingQueue.element().arrivalTime += CPU_CYCLE_TIME;
				
				
				if(waitingQueue.element().cpuTime<=0){
					int waitingTime = time - waitingQueue.element().arrivalTime + CPU_CYCLE_TIME;
					result.add(new Result(waitingQueue.element().jobName, waitingQueue.element().symbol, waitingTime));
					
					waitingQueue.remove();
				}else{
					result.add(new Result(waitingQueue.element().jobName, waitingQueue.element().symbol));
				}
				
			}else{							//idle time, no process is waiting
				result.add(new Result());
			}
			
			time += CPU_CYCLE_TIME;
		}
		
		
		return result;
	}
	
	private void order(Queue<Process> waitingQueue){
		int waitingQueueLength = waitingQueue.size();
		Process[] processes = new Process[waitingQueueLength];
		
		for(int i=0; i<waitingQueueLength; i++){
			processes[i] = waitingQueue.poll();
		}
		
		//bubble sort
		Process tempProcess;
		for(int i=1, j; i<waitingQueueLength-1; i++){
			for(j=i+1; j<waitingQueueLength; j++){
				if(processes[i].priority < processes[j].priority){
					tempProcess = processes[i];
					processes[i] = processes[j];
					processes[j] = tempProcess;
				}
			}
		}
		
		for(int i=0; i<waitingQueueLength; i++){
			waitingQueue.add(processes[i]);
		}
	}
}
