/**************************************************
* FUNCTION: ajax
* Sends an ajax request to assign13.rb
***************************************************/
function ajax()
{
    URL = "http://" + document.domain;
    URL += "/cgi-bin/jol10005/assign13.rb?";
    URL += $("form").serialize();
    
    $("#display").fadeOut(200,function(){
        $("#display").load(URL, function(){
                $("#display").fadeIn(1200);
        });
    });
}

/**************************************************
* FUNCTION: loadRegistered
* Loads the list of registered students into display
***************************************************/
function loadRegistered()
{
    URL = "http://" + document.domain;
    URL += "/cgi-bin/jol10005/assign13a.rb";
    
    $("#display").fadeOut(1200,function(){
        $("#display").load(URL, function(){
                $("#display").fadeIn(1200);
        });
    });
}

/**************************************************
* FUNCTION: loadRegistration
* Loads the registration page
***************************************************/
function loadRegistration()
{
    URL = "http://" + document.domain;
    URL += "/cgi-bin/jol10005/assign13registration.rb";
    
    $("#content").fadeOut(800,function(){
        $("#content").load(URL, function(){
                $("#content").fadeIn(1200);
        });
    });
}

/**************************************************
* FUNCTION: loadPurchase
* Loads the purchase page
***************************************************/
function loadPurchase()
{
    URL = "http://" + document.domain;
    URL += "/cgi-bin/jol10005/assign13purchase.rb";

    $("#content").fadeOut(1200,function(){
        $("#content").load(URL, function(){
                $("#content").fadeIn(1200);
        });
    });
}

/**************************************************
* FUNCTION: duet
* toggles the display of second student
***************************************************/
function duet()
{
    type = $("select[name='performance'] option:selected");
    if (type[0].value == "duet")
        $('#secondStudent').show("slow",function(){});
    else
        $('#secondStudent').hide("slow");
}

/**************************************************
* FUNCTION: validateFname
* validates firstname
***************************************************/
function validateFname()
{
    var test = /^[A-Za-z]+$/.test($('#fname').val());
    if (!test)
        $('#errorfname').show();
    else
        $('#errorfname').hide();
    return test;
}

/**************************************************
* FUNCTION: validateLname
* validates last name
***************************************************/
function validateLname()
{
    var test = /^[A-Za-z]+$/.test($('#lname').val());
    if (!test)
        $('#errorlname').show();
    else
        $('#errorlname').hide();
    return test;
}

/**************************************************
* FUNCTION: validateId
* Valiated id
***************************************************/
function validateId()
{
    var test = /\d{2}[\s\-]?\d{3}[\s\-]?\d{4}[\s\-]?/.test($('#id').val());
    if (!test)
        $('#errorid').show();
    else
        $('#errorid').hide();
    return test;
}

/**************************************************
* FUNCTION: validateFname2
* validates second student's first name
***************************************************/
function validateFname2()
{
    type = $("select[name='performance'] option:selected");
    if (type[0].value == "duet")
    {
        var test = /^[A-Za-z]+$/.test($('#fname2').val());
        if (!test)
            $('#errorfname2').show();
        else
            $('#errorfname2').hide();
        return test;
    }
    return true;
}

/**************************************************
* FUNCTION: validateLname2
* Validates second student's last name
***************************************************/
function validateLname2()
{
    type = $("select[name='performance'] option:selected");
    if (type[0].value == "duet")
    {
        var test = /^[A-Za-z]+$/.test($('#lname2').val());
        if (!test)
            $('#errorlname2').show();
        else
            $('#errorlname2').hide();
        return test;
    }
    return true;
}

/**************************************************
* FUNCTION: validateId2
* Validates second student's id
***************************************************/
function validateId2()
{
    type = $("select[name='performance'] option:selected");
    if (type[0].value == "duet")
    {
        var test = /\d{2}[\s\-]?\d{3}[\s\-]?\d{4}[\s\-]?/.test($('#id2').val());
        if (!test)
            $('#errorid2').show();
        else
            $('#errorid2').hide();
        return test;
    }
    return true;
}

/**************************************************
* FUNCTION: validateRoom
* Validates the room number
***************************************************/
function validateRoom()
{
    var test = /^\w+$/.test($('#room').val());
    if (!test)
        $('#errorroom').show();
    else
        $('#errorroom').hide();
    return test;
}

/**************************************************
* FUNCTION: validateSkill
* Checks if a skill level was selected
***************************************************/
function validateSkill()
{
    var checked = $("input[name='skill']:checked").val();
    if (!!checked)
        $('#errorskill').hide();
        else
        $('#errorskill').show();
    return !!checked;
}

/**************************************************
* FUNCTION: validateInstrument
* Checks if an instrument was selected
***************************************************/
function validateInstrument()
{
    var checked = $("input[name='instrument']:checked").val();
    if (!!checked)
        $('#errorinstrument').hide();
        else
        $('#errorinstrument').show();
    return !!checked;
}

/**************************************************
* FUNCTION: validateAll
* Validates the all input from the form.
* If valid, it makes an ajax request to display registered students
***************************************************/
function validateAll()
{
    var test1 = validateFname();
    var test2 = validateLname();
    var test3 = validateFname2();
    var test4 = validateLname2();
    var test5 = validateRoom();
    var test6 = validateSkill();
    var test7 = validateInstrument();
    var test8 = validateId();
    var test9 = validateId2();

    if (test1 && test2 && test3 && test4 &&
        test5 && test6 && test7 && test8 && test9)
        ajax();
}

/**************************************************
* FUNCTION: getTotal 
* gets the total purchase price for ticekts
***************************************************/
function getTotal()
{
    var show = $("select[name='performance'] option:selected").val();
    var num =  $("select[name='numTickets'] option:selected").val();
    total = show * num;
    string = "$" + total.toFixed(2);
    $('#total').text(string);
}

/**************************************************
* FUNCTION: loadInfo
* Loads the description for the events on purchase page
***************************************************/
function loadInfo()
{

    var extrav = "<img src='http://" + document.domain + "/~jolleyboy/images/extrav.jpg'/>";
    extrav += "<p>Join us for an all day musical extravaganza!";
    extrav +=" Select performers from Brigham Young";
    extrav +=" University -- Idaho will be displaying their talents";
    extrav +=" across the entire campus.  5 dollars gets your hand";
    extrav +=" stamped granting entry to any of these mini performances.</p>";

    var univ = "<img src='http://" + document.domain + "/~jolleyboy/images/choir.jpg'/><p>";
    univ +=" The University Choir will be performing Christmas carols";
    univ +=" for one and all.  Tickets priced low to allow even the ";
    univ +=" poorest students to attend.  Come and fill";
    univ +=" your festive spirit to its holiday max!";
    univ +=" Please dress your best.</p>";

    var teacher = "<img src='http://" + document.domain + "/~jolleyboy/images/teachers.jpg'/><p>";
    teacher +=" Come listen to your favorite professors play their hearts out";
    teacher +=" in this yearly tradition of the Brigham Young University -- Idaho Music department.";
    teacher +=" Your teachers will be playing Christmas themed music in a casual atmosphere.";
    teacher +=" Concert dress is not required.</p>";

    var motab = "<img src='http://" + document.domain + "/~jolleyboy/images/motab.jpg'/><p>";
    motab +=" The Mormon Tabernacle Choir is joining us for a special Christmas themed ";
    motab +=" concert right in our back yard.  Tickets are a steal at $25 dollars";
    motab +=" a person.  Please take advantage of this once in a lifetime oportunity to";
    motab +=" welcome Motab to Rexburg, Idaho.</p>";

    var show = $("select[name='performance'] option:selected").text();
    if (show == "Extravaganza")
        $('#display').html(extrav);
    else if (show == "University Choir's Christmas")
        $('#display').html(univ);
    else if (show == "Teacher's Ensemble")
        $('#display').html(teacher);
    else if (show == "Christmas with Motab")
        $('#display').html(motab);
}

/**************************************************
* FUNCTION: buy
* Loads the confirmation page for purchasing tickets 
***************************************************/
function buy(){
    confirm = "<h2> Thank you for your purchase </h2> <div id='content-left'>Your student account has been charged " + string + "</div>";
    $('#content').html(confirm);
}