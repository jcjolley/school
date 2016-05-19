/***********************************************************
* FUNCTION: validateName
* This function validates the input of name
************************************************************/
function validateName(name)
{
//convert our parameter to a string
name = String(name);

//make sure it only contains letters without spaces
var stringIndex = name.search(/^[A-Za-z]+$/);

//stringIndex holds the position of the search.  We want it at 0
if (stringIndex == "0")
   return true;
else
   return false;
}
/***********************************************************
* FUNCTION: validatePhone
* This function validates the input of phone
************************************************************/
function validatePhone(phone)
{
//convert our parameter to a string
phone = String(phone);

//make sure it matches the format of a phone number
var stringIndex = phone.search(/\(?\d{3}\)?\s?\d{3}\-?\s?\d{4}$/);

//stringIndex holds the position of the search.  We want it at 0
if (stringIndex == "0")
   return true;
else
   return false;

}

/***********************************************************
* FUNCTION: notEmpty
* This function makes sure a field is not empty 
************************************************************/
function notEmpty(element)
{
   //convert our parameter to a string
   element = String(element);

   //make sure it matches the format of a element
   var stringIndex = element.search(/^\w+/);

   //stringIndex holds the position of the search.  We want it at 0
   if (stringIndex == "0")
      return true;
   else
      return false;
}

/***********************************************************
* FUNCTION: validateEmail
* This function validates the input of email
************************************************************/
function validateEmail(email)
{
//convert our parameter to a string
email = String(email);

//make sure it only contains letters without spaces
var stringIndex = email.search(/^\w*\@\w*\.[A-Za-z]{2,4}$/);

//stringIndex holds the position of the search.  We want it at 0
if (stringIndex == "0")
   return true;
else
   return false;
}

/***********************************************************
* FUNCTION: validateCity
* This function validates the input of city
************************************************************/
function validateCity(city)
{
//convert our parameter to a string
city = String(city);

//make sure it only contains letters without spaces
var stringIndex = city.search(/^[A-Za-z]*\s?[A-Za-z]*\s?[A-Za-z]*$/);

//stringIndex holds the position of the search.  We want it at 0
if (stringIndex == "0")
   return true;
else
   return false;
}

/***********************************************************
* FUNCTION: validateZip
* This function validates the input of zip
************************************************************/
function validateZip(zip)
{
//convert our parameter to a string
zip = String(zip);

//make sure it only contains letters without spaces
var stringIndex = zip.search(/^\d{5}$/);

//stringIndex holds the position of the search.  We want it at 0
if (stringIndex == "0")
   return true;
else
   return false;
}

/***********************************************************
* FUNCTION: validateCard
* This function validates the input of card
************************************************************/
function validateCard(card)
{
//convert our parameter to a string
card = String(card);

//make sure it matches the format of a card number
var stringIndex = card.search(/^\d{4}\-?\s?\d{4}\-?\s?\d{4}\-?\s?\d{4}$/);

//stringIndex holds the position of the search.  We want it at 0
if (stringIndex == "0")
   return true;
else
   return false;
}

/**************************************************
*FUNCTION: displayState
*Displays valid/invalid 
***************************************************/
function displayState(fValid, error, input)
{
   "use strict";
   if(fValid) //If the input is valid
   {
     //don't show the error message
     error.style.visibility="hidden";
     return true;
   }
   else //If the input is not valid
   {
     //show the error message
     error.style.visibility="visible";

     //set focus to the incorrect field
     input.focus();
     return false;
   }
}

/**************************************************
*FUNCTION: getTotal
*Sees what is checked and gets the total. 
***************************************************/
function getTotal()
{
   total = 0;
   wheat = document.getElementById('wheat').checked;
   bread = document.getElementById('bread').checked;
   milk =  document.getElementById('milk').checked;
   cheese =document.getElementById('cheese').checked;

   if (wheat)
      total += 3;
   if (bread)
      total += 2.5;
   if (milk)
      total += 4;
   if (cheese)
      total += 3.5;

   total = total.toFixed(2);
   document.getElementById('output').innerHTML="Total: $" + total;
}

/**************************************************
*FUNCTION: validateAll
*Checks everything, returns true if it all checks out
***************************************************/
function validateAll()
{

   element = document.getElementById('fname');
   if (!displayState(validateName(document.getElementById('fname').value), document.getElementById('vfname'), document.getElementById('fname')))
   {
      element = document.getElementById('fname');
      element.focus();
      return false;
   }
    if (!displayState(validateName(document.getElementById('lname').value), document.getElementById('vlname'), document.getElementById('lname')))
   {
      element = document.getElementById('lname');
      element.focus();
      return false;
   }
   if (!displayState(validatePhone(document.getElementById('phone').value),document.getElementById('vphone'), document.getElementById('phone')))
   {
      element = document.getElementById('phone');
      element.focus();
      return false;
   }
   if (!displayState(validateEmail(document.getElementById('email').value), document.getElementById('vemail'), document.getElementById('email')))
   {
      element = document.getElementById('email');
      element.focus();
      return false;
   }
   if (!displayState(notEmpty(document.getElementById('address').value), document.getElementById('vaddress'), document.getElementById('address')))
   {
      element = document.getElementById('address');
      element.focus();
      return false;
   }
   if (!displayState(validateCity(document.getElementById('city').value), document.getElementById('vcity'), document.getElementById('city')))
   {
      element = document.getElementById('city');
      element.focus();
      return false;
   }
   if (!displayState(validateZip(document.getElementById('zip').value),document.getElementById('vzip'), document.getElementById('zip')))
   {
      element = document.getElementById('zip');
      element.focus();
      return false;
   }
   if (!displayState(validateCard(document.getElementById('card').value),document.getElementById('vcard'), document.getElementById('card')))
   {
      element = document.getElementById('card');
      element.focus();
      return false;
   }
   return true;
}