/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 06.Sep.2015
* Comment: This piece of program solves 8 puzzle problem using A* search algorithm.
**/

package eightPuzzle;

import java.util.Random;

public class AStarSearch {
	int SWAP_WITH_TOP=0, SWAP_WITH_RIGHT=1, SWAP_WITH_BOTTOM=2, SWAP_WITH_LEFT=3;
	
	int numberOfBoxsInRow = 3;
	int numberOfBoxs = numberOfBoxsInRow*numberOfBoxsInRow;	// only block 0 has the capability to swap with others.
	
	int[] box;
	
	AStarSearch(){
		box = new int[numberOfBoxs];
		
		initialize();
	}
	
	////////////////////////////////////////////////////////////////////////////////
	
	private void initialize(){
		System.out.println("##\t\tINITIALIZING");
		
		for(int i=0; i<numberOfBoxs; i++){
			box[i] = i;
		}
	}
	
	////////////////////////////////////////////////////////////////////////////////
	
	public void shuffle(){
		System.out.println("##\t\tSHUFFLING");
		
		Random random = new Random();
		int loop = random.nextInt(20)+15;
		int direction;
		
		for(int i=0; i<loop; i++){
			direction = random.nextInt(4);
			
			while(!swap(box, direction)){
				direction = random.nextInt(4);
			}
		}
	}
	
	public void printBlocks(){
		System.out.print("# Box Structure:\n\t\t");
		for(int i=0; i<numberOfBoxs; i++){
			System.out.print(box[i]+" ");
			if( (i+1)%numberOfBoxsInRow == 0 ){
				System.out.print("\n\t\t");
			}
		}
		System.out.print("\n\n");
	}
	
	////////////////////////////////////////////////////////////////////////////////
	
	public void startMaching(int limit){
		System.out.println("##\t\tSTARTING_PROCESS");
		
		printBlocks();
		
		int heuristics = 9999, recentHeuristics;
		int swapDirection=5;
		int cycles=0;
		int frobiddenSwapDirection=5;
		
		while(heuristics>0 && cycles<limit){
			heuristics = 9999;
			
			System.out.println("\n\n# Cycle No : " + (cycles+1));
			for(int i=0; i<4; i++){
				if(i==frobiddenSwapDirection){
					continue;
				}
				
				int[] newBox = clone(box);
				if(swap(newBox, i)){
					recentHeuristics = calculateHeuristics(newBox);
					System.out.println(i + " " + recentHeuristics);	//test
					
					if(heuristics>recentHeuristics){
						heuristics=recentHeuristics;
						swapDirection = i;
					}
				}
			}
			
			if(swapDirection == SWAP_WITH_BOTTOM){
				frobiddenSwapDirection = SWAP_WITH_TOP;
			}else if(swapDirection == SWAP_WITH_TOP){
				frobiddenSwapDirection = SWAP_WITH_BOTTOM;
			}else if(swapDirection == SWAP_WITH_LEFT){
				frobiddenSwapDirection = SWAP_WITH_RIGHT;
			}else{
				frobiddenSwapDirection = SWAP_WITH_LEFT;
			}
			
			swap(box, swapDirection);
			System.out.println("# Heuristics: "+heuristics);
			printBlocks();
			
			cycles++;
		}
	}
	
	public int[] clone(int[] box){
		int[] boxClone = new int[box.length];
		for(int i=0; i<box.length; i++){
			boxClone[i] = box[i];
		}
		
		return boxClone;
	}
	
	public boolean swap(int[] box, int swapWith){
		int zeroBoxIndex=0, swapBoxIndex=0;
		for(int i=0; i<numberOfBoxs; i++){
			if(box[i]==0){
				zeroBoxIndex=i;
				break;
			}
		}
		
		if(swapWith == SWAP_WITH_TOP){
			swapBoxIndex = zeroBoxIndex-numberOfBoxsInRow;
		}else if(swapWith == SWAP_WITH_BOTTOM){
			swapBoxIndex = zeroBoxIndex+numberOfBoxsInRow;
		}else if(swapWith == SWAP_WITH_RIGHT){
			if((zeroBoxIndex+1)%numberOfBoxsInRow == 0){	//end of row
				return false;
			}
			
			swapBoxIndex = zeroBoxIndex+1;
		}else{
			swapBoxIndex = zeroBoxIndex-1;
			
			if((swapBoxIndex+1)%numberOfBoxsInRow == 0){	//start of row
				return false;
			}
		}
		
		if(swapBoxIndex<0 || swapBoxIndex>=numberOfBoxs){
			return false;
		}
		
		int temp = box[zeroBoxIndex];
		box[zeroBoxIndex] = box[swapBoxIndex];
		box[swapBoxIndex] = temp;
		
		return true;
	}
	
	public int calculateHeuristics(int[] box){
		int heuristics = 0;
		int numericalDifference, columnDifference, rowDifference, totalDiference;
		
		for(int i=0; i<numberOfBoxs; i++){
			if(box[i]==0){
				continue;
			}
			
			numericalDifference = Math.abs(i-box[i]);
			columnDifference = numericalDifference/numberOfBoxsInRow;
			rowDifference = numericalDifference%numberOfBoxsInRow;
			totalDiference = columnDifference+rowDifference;
			
			heuristics += totalDiference;
		}
		
		return heuristics;
	}
	
	////////////////////////////////////////////////////////////////////////////////
	
	public static void main(String[] args) {
		
		AStarSearch aStarSearch = new AStarSearch();

		aStarSearch.shuffle();
		aStarSearch.startMaching(1000);
	}
}
