/************************************************************************************************
* Developer: Minhas Kamal(BSSE-0509, IIT, DU)													*
* Date: Sep-2014																				*
*************************************************************************************************/

package thread.shortestJob.premitive;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

import thread.utilClasses.Graph;

import thread.utilClasses.Process;
import thread.utilClasses.Result;

public class ShortestJobFirstPremitive {
	public Queue<Process> processQueue = new LinkedList<Process>();
	public Queue<Result> results = new LinkedList<Result>();

	public void shortestJobFirstPremitiveImpl(String fileName){
		int noOfProcess;
		processQueue = takeInput(fileName);
		noOfProcess = processQueue.size();
		
		order(processQueue);
		
		results = new CPU().runProcess(processQueue);
		
		float totalWaitingTime = 0;
		Queue<Character> symbol = new LinkedList<Character>();
		
		for(Result result: results){
			//System.out.println(result.symbol + " -> " + result.waitingTime);

			symbol.add(result.symbol);
			
			if(result.waitingTime>0){
				totalWaitingTime += result.waitingTime;
			}
		}
		
		//System.out.println("\n\n\nAverage waiting time: " + totalWaitingTime/noOfProcess);

		new Graph(symbol, totalWaitingTime/noOfProcess).setVisible(true);
	}
	
	private Queue<Process> takeInput(String fileName){
		Queue<Process> processQueue = new LinkedList<Process>();
		
		try {
			String string = new String(); // for temporary data store
			BufferedReader mainBR = new BufferedReader(new InputStreamReader(getClass().getResourceAsStream(fileName)));

			String jobName;
			int arrivalTime;
			int cpuTime;
			int priority;
			char symbol;
			
			int startIndex=0;
			int stopIndex=-1;
			
			string = mainBR.readLine();
			while (string != null) { // reading step by step
				startIndex=stopIndex+1;
				stopIndex=string.indexOf(' ', startIndex);
				jobName = string.substring(startIndex, stopIndex);
				
				startIndex=stopIndex+1;
				stopIndex=string.indexOf(' ', startIndex);
				arrivalTime = Integer.parseInt(string.substring(startIndex, stopIndex));
				
				startIndex=stopIndex+1;
				stopIndex=string.indexOf(' ', startIndex);
				cpuTime = Integer.parseInt(string.substring(startIndex, stopIndex));
				
				startIndex=stopIndex+1;
				stopIndex=string.indexOf(' ', startIndex);
				priority = Integer.parseInt(string.substring(startIndex, stopIndex));
				
				startIndex=stopIndex+1;
				stopIndex=string.indexOf('\n', startIndex);
				symbol = string.charAt(startIndex);
				
				processQueue.add(new Process(jobName, arrivalTime, cpuTime, priority, symbol));
				
				string = mainBR.readLine();
			}

			mainBR.close(); // closing the file

		}catch (Exception e) {
			e.printStackTrace();
		}
		
		/*///test
		processQueue.add(new Process("process-1", 100, 400, 2, '1'));
		processQueue.add(new Process("process-2", 200, 600, 1, '2'));
		processQueue.add(new Process("process-3", 100, 100, 1, '3'));
		processQueue.add(new Process("process-4", 300, 300, 3, '4'));
		/**/
		return processQueue;
	}
	
	private void order(Queue<Process> processQueue){
		int waitingQueueLength = processQueue.size();
		Process[] processes = new Process[waitingQueueLength];
		
		for(int i=0; i<waitingQueueLength; i++){
			processes[i] = processQueue.poll();
		}
		
		//bubble sort
		Process tempProcess;
		for(int i=0, j; i<waitingQueueLength-1; i++){
			for(j=i+1; j<waitingQueueLength; j++){
				if(processes[i].arrivalTime > processes[j].arrivalTime){
					tempProcess = processes[i];
					processes[i] = processes[j];
					processes[j] = tempProcess;
				}
			}
		}
		
		for(int i=0; i<waitingQueueLength; i++){
			processQueue.add(processes[i]);
		}
	}
	
	public static void main(String[] args) {
		new ShortestJobFirstPremitive().shortestJobFirstPremitiveImpl("/thread/Input");
	}
}
