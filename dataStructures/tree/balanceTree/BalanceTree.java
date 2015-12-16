/**
* Developer: Minhas Kamal(BSSE0509, IIT, DU)
* Date: 09-Feb-2015
**/

package balanceTree;

import java.util.LinkedList;
import java.util.Scanner;

public class BalanceTree {

	public void CreateBalanceTree() {
		Touple[] touples = takeInput();
//		Touple[] touples = takeInput2();
		//traverse(touples);
		
		constructBalanceTree(touples, 0, touples.length, 0);
		
		//traverse(touples);
	}
	
	@SuppressWarnings("resource")
	private Touple[] takeInput(){
		LinkedList<Touple> touples = new LinkedList<Touple>();
		
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter your touples(0 for exit): ");
		
		String[] tempStrings;
		tempStrings = scanner.nextLine().split(" ");
		while(!tempStrings[0].equals("0")){
			touples.add(new Touple(tempStrings));
			tempStrings = scanner.nextLine().split(" ");
		}
		
		return touples.toArray(new Touple[0]);
	}
	
	private Touple[] takeInput2(){
		LinkedList<Touple> touples = new LinkedList<Touple>();
		
		int[] i = new int[3];
		
		i[0]=2; i[1]=3; i[2]=9; touples.add(new Touple(i.clone()));
		i[0]=4; i[1]=9; i[2]=4; touples.add(new Touple(i.clone()));
		i[0]=3; i[1]=5; i[2]=0; touples.add(new Touple(i.clone()));
		i[0]=6; i[1]=8; i[2]=2; touples.add(new Touple(i.clone()));
		i[0]=8; i[1]=1; i[2]=1; touples.add(new Touple(i.clone()));
		i[0]=1; i[1]=4; i[2]=5; touples.add(new Touple(i.clone()));
		i[0]=6; i[1]=2; i[2]=8; touples.add(new Touple(i.clone()));
		i[0]=7; i[1]=3; i[2]=2; touples.add(new Touple(i.clone()));
		
		return touples.toArray(new Touple[0]);
	}
	
	private void traverse(Touple[] touples) {
		String str = "[" + touples[0].dupm();
		for(int i=1; i<touples.length; i++){
			str += "," + touples[i].dupm();
		}
		str += "]";
		
		System.out.println(str);
	}
	
	private void partialSort(Touple[] touples, int startRange, int finishRange, int elementNumber) {
		for(int i=startRange; i<finishRange; i++){
			for(int j=i; j<finishRange; j++){
				if(touples[i].values[elementNumber] > touples[j].values[elementNumber]){
					Touple temp = touples[i];
					touples[i] = touples[j];
					touples[j] = temp;
				}
			}
		}
	}
	
	private void constructBalanceTree(Touple[] touples, int startRange, int finishRange, int step) {
			
		partialSort(touples, startRange, finishRange, step%touples[0].values.length);
			
		int divider = (startRange+finishRange)/2;
		System.out.println(touples[divider].values[step%touples[0].values.length]);
		traverse(touples);
		
		if(finishRange-startRange>2){
			step++;
			constructBalanceTree(touples, startRange, divider, step);
			constructBalanceTree(touples, divider, finishRange, step);
		}
		
		return ;
	}
	
	public static void main(String[] args) {
		BalanceTree balanceTree = new BalanceTree();
		balanceTree.CreateBalanceTree();
	}
}
