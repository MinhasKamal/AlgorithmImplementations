/**
* Developer: Minhas Kamal(BSSE0509, IIT, DU)
* Date: 06-Apr-2015
**/

package dbms.kdTree;

import java.util.LinkedList;
import java.util.Scanner;

public class KdTreeImpl {
	private static int[][] data;
	private static LinkedList<LinkedList<Integer>> tree = new LinkedList<>();
	
	public static void main(String[] args) {
		//data = convertStringToInt(takeInput());
		
		data = takeInput2();
		traverse(data);
		System.out.println("\n##################\n");
		
		int dimention = 0;
		int level = 0;
		constructTree(data, 0, data.length, dimention, level);
		
		System.out.println("\n##################\n");
		traverse(data);
		
		printTree(tree);
	}
	
	private static String[][] takeInput(){
		LinkedList<String[]> inputData = new LinkedList<>();
		
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter your input (0 for exit): ");
		String[] inputStr = scanner.nextLine().split(" ");
		while(!inputStr[0].equals("0")){
			inputData.add(inputStr);
			inputStr = scanner.nextLine().split(" ");
		}
		
		String[][] stringData = new String[inputData.size()][];
		stringData = inputData.toArray(stringData);
		
		return stringData;
	}
	
	private static int[][] convertStringToInt(String[][] strdata){
		int firstDLen = strdata.length;
		int secondDLen = strdata[0].length;
		
		int[][] data = new int[firstDLen][secondDLen];
		for(int i=0; i<firstDLen; i++){
			for(int j=0; j<secondDLen; j++){
				data[i][j] = Integer.parseInt(strdata[i][j]);
			}
		}
		
		return data;
	}
	
	private static int[][] takeInput2(){
		/*int[][] data2={{8, 5, 9},
				{3, 4, 8},
				{2, 9, 7},
				{7, 7, 6},
				{1, 3, 5},
				{4, 6, 4}};*/
		
		int[][] data2={{6, 1}, {5, 5}, {9, 6}, {3, 6}, {4, 9}, {4, 0}, {7, 9}, {2, 9}}; 
		
		return data2;
	}
	
	private static void traverse(int[][] data){
		for(int i=0; i<data.length; i++){
			System.out.print("(" + data[i][0]);
			for(int j=1; j<data[i].length; j++){
				System.out.print("," + data[i][j]);
			}
			System.out.print(")");
		}
		System.out.println();
	}
	
	private static void constructTree(int[][] data, int from, int to, int dimention, int level){
		//restricted bubble sort
		for(int i=from; i<to-1; i++){
			for(int j=i+1; j<to; j++){
				if(data[i][dimention] > data[j][dimention]){
					int[] temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
		
		//if there is more than one member
		if(to-from > 1){
			traverse(data);//output
			if(tree.size()<level){
				LinkedList<Integer> ints = new LinkedList<Integer>();
				tree.add(ints);
			}
			tree.get(level).add(data[(from+to)/2][dimention]);
			
			level++;
			dimention++;
			if(dimention>=data[0].length){
				dimention=0;
			}
			
			//recursive call
			constructTree(data, from, (from+to)/2, dimention, level);
			constructTree(data, (from+to)/2, to, dimention, level);
		}
		
		return;
	}
	
	private static void printTree(LinkedList<LinkedList<Integer>> tree){
		for(LinkedList<Integer> elem: tree){
			for(int node: elem){
				System.out.println(node + "\t");
			}
			System.out.println();
		}
	}
}
