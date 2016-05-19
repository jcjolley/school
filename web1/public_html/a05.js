/**************************************************
*FUNCTION: validateAPR
*This function validates the input of apr
***************************************************/
function validateAPR(apr)
{
    //convert our parameter to a string
    apr = String(apr);

    //make sure it only contains digits
    var ok = apr.search(/^\d+[.]?\d*$/g);
    
    //'ok' holds the position of the search.  We want it at 0
    if (ok == 0)
    {
        return true;
    }
    else
        return false;
}


/**************************************************
*FUNCTION: validateTerm
*This function validates the input of term
***************************************************/
function validateTerm(term)
{

    //convert our parameter to a string                
    term = String(term);

    //make sure it only contains digits
    var ok = term.search(/^\d+$/g);

    //'ok' holds the position of the search.  We want it at 0
    if (ok == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**************************************************
*FUNCTION: validateAmount
*This function validates the input of amount
***************************************************/
function validateAmount(amount)
{
 
    //convert our parameter to a string
    amount = String(amount);

    //make sure it only contains digits
    var ok = amount.search(/^\d+$/g);

    //'ok' holds The position of the search.  We want it at 0
    if (ok == 0)
    {
        return true;
    }
    else
        return false;
}

/**************************************************
*FUNCTION: Calculate mortage
*This function calculates your monthly mortgage payment
***************************************************/
function calculateMortgage(amount, term, apr)
{
    "use strict";
    if(validateAPR(apr) && validateTerm(term) && validateAmount(amount))
    {
        //Term is in years, we need it in months
        var numPayments = term * 12;

        //We want to change the % to a decimal
        var interest = apr / 100;

        //Store the repeated (1 + i)^n from the formula.
        var compInterest = Math.pow(1 + interest, numPayments);

        //Calculate the payment
        var payment = amount * (interest * compInterest)/(compInterest - 1);
        payment = payment.toFixed(2);  //make the format look like dollars
        document.getElementById('display').innerHTML="$" + payment;
        
        //display the payment
        document.getElementById('display').style.display="block";
       
    }
}

/**************************************************
*FUNCTION: displayState
*Displays valid/invalid 
***************************************************/
function displayState(fValid, element)
{
    "use strict";
    if(fValid) //If the input is valid
    {
        //don't show the error message
        element.style.display="none";
        return true;
    }
    else //If the input is not valid
    {
        //hide the mortgage calculation
        document.getElementById('display').style.display="none";
        //show the error message
        element.style.display="block";
        return false;
    }
}