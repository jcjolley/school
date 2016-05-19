/**************************************************
*FUNCTION: validateAmount
*This function validates the input of amount
***************************************************/
function validateAmount(amount)
{
    //convert our parameter to a string
    amount = document.getElementById("amount").value;
    var error = document.getElementById("amountError");
    
    //make sure it only contains digits
    var ok = amount.search(/^\d+$/g);

    //'ok' holds The position of the search.  We want it at 0
    if (ok == 0)
    {
        //don't show the error message
        error.style.visibility="hidden";
        return true;
    }
    else //If the input is not valid
    {
        //hide the mortgage calculation
        document.getElementById('display').style.visibility="hidden";
        //show the error message
        error.style.visibility="visible";
        return false;
    }
}

/**************************************************
*FUNCTION: validateTerm
*This function validates the input of term
***************************************************/
function validateTerm(term)
{

    //convert our parameter to a string                
    term = document.getElementById("term").value;
    var error = document.getElementById("termError");

    //make sure it only contains digits
    var ok = term.search(/^\d+$/g);

    //'ok' holds the position of the search.  We want it at 0
    if (ok == 0)
    {
        //don't show the error message
        error.style.visibility="hidden";
        return true;
    }
    else //If the input is not valid
    {
        //hide the mortgage calculation
        document.getElementById('display').style.visibility="hidden";
        //show the error message
        error.style.visibility="visible";
        return false;
    }
}

/**************************************************
*FUNCTION: validateApr
*This function validates the input of apr
***************************************************/
function validateApr()
{
    //convert our parameter to a string
    apr = document.getElementById("apr").value;
    var error = document.getElementById("aprError");
    //make sure it only contains digits
    var ok = apr.search(/^\d+[.]?\d*$/g);
    
    //'ok' holds the position of the search.  We want it at 0
    if (ok == 0)
    {
        //don't show the error message
        error.style.visibility="hidden";
        return true;
    }
    else //If the input is not valid
    {
        //hide the mortgage calculation
        document.getElementById('display').style.visibility="hidden";
        //show the error message
        error.style.visibility="visible";
        return false;
    }
}

/**************************************************
*FUNCTION: ajax
*This function validates the input of all functions;
***************************************************/
function ajax()
{
    var URL = "http://157.201.194.254/cgi-bin/jol10005/assign10";
    var query = "?amount=" + amount.value;
    query += "&term=" + term.value;
    query += "&apr=" + apr;
    
    URL += query;
    
    //Make an XMLHttpRequest object for the right browser
    if (window.XMLHttpRequest) //everything other than IE
    {
      xmlhttp=new XMLHttpRequest();
    }
    else  //for IE
    {
      xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
    }

    //our callback function
    xmlhttp.onreadystatechange=function()
    {
      //when it's ready and found the file
      if (xmlhttp.readyState==4 && xmlhttp.status==200)
      {
      //insert it into display
      document.getElementById("display").innerHTML=xmlhttp.responseText;
      }
    }

    //call the methods to actually get it to do the work! :)
    xmlhttp.open("GET",URL,true);
    xmlhttp.send();
}

/**************************************************
*FUNCTION: validateAll
*This function validates the input of all functions;
***************************************************/
function validateAll()
{
    if (validateAmount() && validateTerm() && validateApr())
    {
        ajax();
        document.getElementById("display").style.visibility="visible";
    }
    return;
}