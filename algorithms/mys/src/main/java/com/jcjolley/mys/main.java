/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.jcjolley.mys;

import com.google.common.collect.Sets;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;
import static java.util.stream.Collectors.toSet;
import java.util.stream.IntStream;

/**
 *
 * @author jolley
 */
public class main {

	private Integer vowelCount(String word){
		Set<Character> vowels = Sets.newHashSet('a', 'e', 'i', 'o', 'u');
		return word.chars()
				.mapToObj(c -> (char)c)
				.filter(c -> vowels.contains(c))
				.collect(toSet())
				.size();
	}

	private Integer countVowelsLeft(String word){
		return word.chars()
				.mapToObj(c -> (char)c)
				.filter(c -> vowelsLeft.contains(c))
				.collect(toSet())
				.size();
	}

	private Set<Integer> factors (Integer n)
	{
		Set<Integer> factors = Sets.newHashSet();
		int i = 2;
		while (i < n)
			if (n % i == 0)
				factors.add(i);
		return factors;
	}

	private char getFirstScore()
	{
		wordScore.entrySet().stream()
			
	}
	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		// TODO code application logic here
	}
	private Map<String, Integer> wordScore;
	private Set<Character> vowelsLeft;
	
}	
