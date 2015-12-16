/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 01.Sep.2015
* Comment: This piece of code solves n-Queen problem using Genetic Algorithm.
**/

package nQueenProblem;

import java.util.Random;

public class Player {
	int boardSize;
	int population;
	Board[] board;
	
	public Player() {
		boardSize = 8;
		population = 4;
		board = new Board[population];
		for(int popu=0; popu<population; popu++){
			board[popu] = new Board(boardSize);
		}

		initializeBoardRandomly();
		
	}
	
	private void initializeBoardRandomly(){
		for(int popu=0; popu<population; popu++){
			Random random = new Random();
			int column=0;
			
			for(int i=0; i<boardSize; i++){
				column = Math.abs(random.nextInt()%boardSize);
				
				board[popu].setQueen(i, column);
			}
		}
	}
	
	public void startEvolution(){
		int generation=0;
		int weak, strong;
		int weakAmount, strongAmount;
		
		while(generation<5000){
			System.out.println("# GeneRation: " + generation);
			
			weak = strong = 0;
			weakAmount = strongAmount = board[0].countAttack();
			for(int i=1; i<population; i++){
				int amount = board[i].countAttack();;
				if(weakAmount < amount){
					weakAmount = amount;
					weak = i;
				}
				if(strongAmount > amount){
					strongAmount = amount;
					strong = i;
				}
			}
			
			if(board[strong].countAttack()==0){
				System.out.println("\n\n\n## SOLVED!!\n***************\n"+board[strong].toString()+"***************");
				break;
			}
			
			board[weak] = board[strong].getCopy();
			
			for(int i=0; i<population/2; i++){
				board[i].crossOver(board[population-i-1]);
			}
			
			for(int i=0; i<population; i++){
				board[i].occurMutation();
			}
			
			generation++;
		}
		
		if(generation>=5000){
			System.out.println("\n\n\n## UNSOLVED!!!!!!!");
		}
	}
	
	
	public static void main(String[] args) {
		Player player = new Player();
		player.startEvolution();
		
//		for(int i=0; i<4; i++){
//			System.out.print(player.board[i].toString());
//			System.out.println(player.board[i].countAttack()+"\n\n\n");
//		}
	}
}
