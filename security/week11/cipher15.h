/*******************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Case Cipher example.
********************************************************************/
#ifndef CIPHER15_H
#define CIPHER15_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher15 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Joshua Jolley"; }
   virtual std::string getCipherName()  { return "Baconian Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Sir Francis Bacon, http://easyciphers.com/");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      str =  "lookupMap char -> string \n";
      str += "\ta -> AAAAA  g -> AABBA  m -> ABABB  s -> BAAAB  y -> BABBA\n";
      str += "\tb -> AAAAB  h -> AABBB  n -> ABBAA  t -> BAABA  z -> BABBB\n";
      str += "\tc -> AAABA  i -> ABAAA  o -> ABBAB  u -> BAABB\n";
      str += "\td -> AAABB  j -> BBBAA  p -> ABBBA  v -> BBBAB\n";
      str += "\te -> AABAA  k -> ABAAB  q -> ABBBB  w -> BABAA\n";
      str += "\tf -> AABAB  l -> ABABA  r -> BAAAA  x -> BABAB\n";
      str += "FOR character c in plaintext:\n";
      str += "\t ciphertext += lookupMap(c) + ' '\n\n";

      // The decrypt pseudocode
      str += "lookupMap string -> char \n" +
      str += "\tAAAAA -> a  AABBA -> g  ABABB -> m  BAAAB -> s  BABBA -> y\n";
      str += "\tAAAAB -> b  AABBB -> h  ABBAA -> n  BAABA -> t  BABBB -> z\n";
      str += "\tAAABA -> c  ABAAA -> i  ABBAB -> o  BAABB -> u\n";
      str += "\tAAABB -> d  BBBAA -> j  ABBBA -> p  BBBAB -> v\n";
      str += "\tAABAA -> e  ABAAB -> k  ABBBB -> q  BABAA -> w\n";
      str += "\tAABAB -> f  ABABA -> l  BAAAA -> r  BABAB -> x\n";
      str += "cipherChars <- split(ciphertext, ' ')\n";
      str += "FOR string c in cipherChars\n";
      str += "\t plaintext += lookupMap(c)";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & source, 
                               const std::string & password)
   {
      std::string destination = source;
      // TODO - Add your code here
      return destination;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & source, 
                               const std::string & password)
   {
      std::string destination = source;
      // TODO - Add your code here
      return destination;
   }
};

#endif // CIPHER13_H
