/************************************************************************************************
* Developer: Minhas Kamal(BSSE-0509, IIT, DU)													*
* Date: Sep-2014																				*
*************************************************************************************************/

package thread.utilClasses;

import java.awt.Color;
import java.awt.Font;
import java.util.*;

import javax.swing.*;

@SuppressWarnings("serial")
public class Graph extends JFrame{
	//**
	// Variable Declaration 																				#*******D*******#
	//**
	private JPanel jPanelMain;
	private JPanel[] jPanelGraph;
	private JLabel jLabel;
	
	//other variables
	private final int LENGTH = 640;
	
	private int parts;
	// End of Variable Declaration 																			#_______D_______#

	/***##Constructor##***/
	public Graph(Queue<Character> symbols, float f) {
		parts = symbols.size();

		initialComponent(symbols, f);
	}

	
	/**
	 * Method for Initializing all the GUI variables, placing them all to specific space on the frame and adding action
	 * listener to them. Also specifies criteria of the main frame.
	 */
	private void initialComponent(Queue<Character> symbols, float f) {
		//**
		// Initialization 																					#*******I*******#
		//**
		jPanelMain = new JPanel();
		jPanelGraph = new JPanel[parts];
		jLabel = new JLabel();
		//other variables
		Queue<Character> uniqueSymbols = new LinkedList<Character>();
		// End of Initialization																			#_______I_______#

		//**
		// Setting Bounds and Attributes of the Elements 													#*******S*******#
		//**
		jPanelMain.setBounds(0, 0, LENGTH+40, 250);
		jPanelMain.setBackground(new Color(-1));
		jPanelMain.setLayout(null);
		
		int partLength = LENGTH/parts;
		for(int i=0; i<parts; i++){
			jPanelGraph[i] = new JPanel();
			
			jPanelGraph[i].setBounds(i*partLength+20, 30, partLength, 60);
			
			char symbol = symbols.poll();
			int position = getPosition(symbol, uniqueSymbols);
			if(position<0){
				uniqueSymbols.add(symbol);
				position = uniqueSymbols.size()-1;
			}
			
			jPanelGraph[i].setBackground(getColor(position));
		}
		
		jLabel.setBounds(20, 130, 600, 40);
		jLabel.setText("Average waiting time: " + f);
		jLabel.setFont(new Font("Tahoma", 1, 20));
		
		// End of Setting Bounds and Attributes 															#_______S_______#

		//**
		// Adding Components 																				#*******A*******#
		//**
		add(jPanelMain);
		
		for(int i=0; i<parts; i++){
			jPanelMain.add(jPanelGraph[i]);
		}
		jPanelMain.add(jLabel);
		// End of Adding Components 																		#_______A_______#

		//**Setting Criterion of the Frame**//
		setIconImage(new ImageIcon(getClass().getResource("")).getImage());
		setBounds(150, 200, LENGTH+40, 250);
		setTitle("");
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setLayout(null);
		setResizable(false);
	}

	//**
	// Action Events 																						#********AE*******#
	//**

	// End of Action Events 																				#________AE_______#

	/********* Main Method *********/
	public static void main(String args[]) {
		/*// Set the NIMBUS look and feel //*/
		try {
			javax.swing.UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
		} catch (Exception ex) {
			// do nothing if operation is unsuccessful
		}

		/* Create and display the form */
		Queue<Character> symbol = new LinkedList<Character>();
		symbol.add('a');symbol.add('a');symbol.add('b');symbol.add('c');
		symbol.add('a');symbol.add('c');symbol.add('c');symbol.add('d');
		symbol.add('a');symbol.add('b');symbol.add('c');symbol.add('e');
		symbol.add('f');symbol.add('f');symbol.add('f');symbol.add('c');
		symbol.add('a');symbol.add('g');symbol.add('g');symbol.add('d');
		symbol.add('h');symbol.add('h');symbol.add('h');symbol.add('e');
		symbol.add('a');symbol.add('a');symbol.add('c');symbol.add('c');
		symbol.add('i');symbol.add('j');symbol.add('k');symbol.add('i');
		symbol.add('j');symbol.add('j');symbol.add('j');symbol.add('k');
		
		Graph gui = new Graph(symbol, 100);
		gui.setVisible(true);
	}

	//**
	// Auxiliary Methods 																					#********AM*******#
	//**
	
	private int getPosition(char symbol, Queue<Character> uniqueSymbols){
		int position = -1;
		
		int p = 0;
		for(Character uniqueSymbol: uniqueSymbols){
			if(symbol==uniqueSymbol){
				position=p;
				break;
			}
			p++;
		}
		
		return position;
	}
	
	private Color getColor(int i){
		i *= 150;
		
		int r = i%256;
		int g = i%200+i%56;
		int b = i%100+i%156;
		
		Color color = new Color(r, g, b);
		return color;
	}
	// End of Auxiliary Methods 																			#________AM_______#
}
