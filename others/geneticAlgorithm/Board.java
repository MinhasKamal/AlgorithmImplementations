/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 01.Sep.2015
* Comment: This is a chess board made only for queens.
**/

package nQueenProblem;

import java.util.Random;

public class Board {
	private int boardSize;
	private int[][] boxes;
	int[] geneticSequence;
	
	
	public Board(int boardSize) {
		this.boardSize = boardSize;
		boxes = new int[boardSize][boardSize];
		geneticSequence = new int[boardSize];
		
		initializeBoard();
	}
	
	public void initializeBoard(){
		for(int i=0; i<boardSize; i++){
			for(int j=0; j<boardSize; j++){
				boxes[i][j] = 0;
			}
			geneticSequence[i]=-1;
		}
	}
	
	public int countAttack(){
		int noOfAttacks = 0;
		
		for(int row=0; row<boardSize; row++){
			//find queen
			int queenColumnNo = findQueen(row);
			if(queenColumnNo==-1){	//not found
				continue;
			}
			
			//column search  ->  ||
			noOfAttacks += countAttackVertical(queenColumnNo);
			//right-diagonal search  ->  \\
			noOfAttacks += countAttackRightDiagonal(queenColumnNo, row);
			//left-diagonal search  ->  //
			noOfAttacks += countAttackLeftDiagonal(queenColumnNo, row);
		}
		
		return noOfAttacks/2;
	}
	
	private int countAttackVertical(int queenColumnNo){
		int noOfAttacks=0;
		
		for(int k=0; k<boardSize; k++){
			if(boxes[k][queenColumnNo]==1){
				noOfAttacks++;
			}
		}
		noOfAttacks--;
		
		return noOfAttacks;
	}
	
	private int countAttackRightDiagonal(int queenColumnNo, int rowNo){
		int noOfAttacks=0;
		
		int startColumn = queenColumnNo-rowNo;
		int startRow = 0;
		if(startColumn<0){
			startRow += (-startColumn);
			startColumn=0;
		}
		for(int m=startRow, n=startColumn; m<boardSize && n<boardSize; m++, n++){
			if(boxes[m][n]==1){
				noOfAttacks++;
			}
		}
		
		noOfAttacks--;
		
		return noOfAttacks;
	}

	private int countAttackLeftDiagonal(int queenColumnNo, int rowNo){
		int noOfAttacks=0;
		
		int startColumn = queenColumnNo+rowNo;
		int startRow = 0;
		if(startColumn>=boardSize){	//not found
			startRow += (startColumn-boardSize+1);
			startColumn=boardSize-1;
		}
		for(int m=startRow, n=startColumn; m<boardSize && n>=0; m++, n--){
			if(boxes[m][n]==1){
				noOfAttacks++;
			}
		}
		
		noOfAttacks--;
		
		return noOfAttacks;
	}
	
	public int findQueen(int row){
		int queenColumnNo=-1;
		for(int j=0; j<boardSize; j++){	
			if(boxes[row][j]==1){
				queenColumnNo=j;
				break;
			}
		}
		return queenColumnNo;
	}
	
	public void setQueen(int row, int column) {
		for(int i=0; i<boardSize; i++){
			boxes[row][i] = 0;
		}
		
		geneticSequence[row] = column;
		boxes[row][column] = 1;
	}
	
	public String toString(){
		String string = "";
		
		for(int i=0; i<boardSize; i++){
			for(int j=0; j<boardSize; j++){
				string += boxes[i][j] + " ";
			}
			string += "\n";
		}
		
		return string;
	}
	
	public void crossOver(Board board){
		int temp=0;
		for(int i=boardSize/2; i<boardSize; i++){
			for(int j=0; j<boardSize; j++){
				temp = board.boxes[i][j];
				board.boxes[i][j] = this.boxes[i][j];
				this.boxes[i][j] = temp;
			}
			temp = board.geneticSequence[i];
			board.geneticSequence[i] = this.geneticSequence[i];
			this.geneticSequence[i] = temp;
		}
	}
	
	public void occurMutation(){
		Random random = new Random();
		
		if(random.nextInt()%10==0){
			int rowNo = Math.abs(random.nextInt()%boardSize);
			int columnNo = Math.abs(random.nextInt()%boardSize);
			
			setQueen(rowNo, columnNo);
		}
	}
	
	public Board getCopy(){
		Board newBoard = new Board(boardSize);
		
		for(int i=0; i<boardSize; i++){
			for(int j=0; j<boardSize; j++){
				newBoard.boxes[i][j] =  this.boxes[i][j];
			}
			newBoard.geneticSequence[i] = this.geneticSequence[i];
		}
		
		return newBoard;
	}
	
	public static void main(String[] args) {
		Board board1 = new Board(8);
		board1.setQueen(0, 1);
		board1.setQueen(1, 1);
		board1.setQueen(2, 1);
		board1.setQueen(3, 1);
		board1.setQueen(4, 1);
		board1.setQueen(5, 1);
		board1.setQueen(6, 1);
		board1.setQueen(7, 1);
		System.out.println(board1.toString());
		
//		Board board2 = new Board(8);
//		board2.setQueen(0, 5);
//		board2.setQueen(1, 5);
//		board2.setQueen(2, 5);
//		board2.setQueen(3, 5);
//		board2.setQueen(4, 5);
//		board2.setQueen(5, 5);
//		board2.setQueen(6, 5);
//		board2.setQueen(7, 5);
//		System.out.println(board2.toString());
//		
//		board2.crossOver(board1);
		
		board1.occurMutation();
		System.out.println(board1.toString());
		board1.occurMutation();
		System.out.println(board1.toString());
		board1.occurMutation();
		System.out.println(board1.toString());
		board1.occurMutation();
		System.out.println(board1.toString());
//		System.out.println(board2.toString());
		
//		System.out.println(board2.countAttack());
	}
}
