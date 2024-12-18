var res = {
    cars: {},
        // {
        //     carId: 1,
        //     in: 5,
        //     out: 13,
        //     lastPosition: 54,
        //     parkingIn: 5,
        //     parkingOut: 10,
        //     arrivalTT: 0,
        //     departureTT: 10,
        //     overallTT: 13,
        // },{
        //     carId: 5,
        //     in: 5,
        //     out: 13,
        //     lastPosition: 45,
        //     parkingIn: 5,
        //     parkingOut: 10,
        //     arrivalTT: 0,
        //     departureTT: 10,
        //     overallTT: 13,
        // }
    // ,
    reserved: ['slot03', 'slot04', 'slot15', 'slot35'],
    obstacle: ['slot05', 'slot40', 'slot25'],
    clock: 0
};


let colors = ['#7FB5FF',  '#F8CB2E', '#446A46', '#AB46D2', '#FF6FB5', '#40DFEF', '#00092C'];
var parkingSlots = []
for(var i=1;i<=40;i++) parkingSlots.push('slot'+(i+'').padStart(2,'0'))
var globalcars = {};
// console.log(res, $('#arena_box'))

var mapping =  {
    0: 'path11',
    1: 'path21',
    2: 'path31',
    3: 'path41',
    4: 'path51',
    5: 'path61',
    6: 'path71',

    7: 'path13',
    8: 'path22',
    9: 'path32',
    10: 'path42',
    11: 'path52',
    12: 'path62',
    13: 'path73',

    14: 'path15',
    15: 'path23',
    16: 'path33',
    17: 'path43',
    18: 'path53',
    19: 'path63',
    20: 'path75',

    21: 'path17',
    22: 'path24',
    23: 'path34',
    24: 'path44',
    25: 'path54',
    26: 'path64',
    27: 'path77',

    28: 'path19',
    29: 'path25',
    30: 'path35',
    31: 'path45',
    32: 'path55',
    33: 'path65',
    34: 'path79',
    35: 'path111',
    36: 'path26',
    37: 'path36',
    38: 'path46',
    39: 'path56',
    40: 'path66',
    41: 'path711',
    42: 'path113',
    43: 'path27',
    44: 'path37',
    45: 'path47',
    46: 'path57',
    47: 'path67',
    48: 'path713',
    49: 'path115',
    50: 'path28',
    51: 'path38',
    52: 'path48',
    53: 'path58',
    54: 'path68',
    55: 'path715',

    56: 'slot36',
    57: 'slot37',
    58: 'slot38',
    59: 'slot39',
    60: 'slot40',
    61: 'slot31',
    62: 'slot32',
    63: 'slot33',
    64: 'slot34',
    65: 'slot35',
    66: 'slot26',
    67: 'slot27',
    68: 'slot28',
    69: 'slot29',
    70: 'slot30',
    71: 'slot21',
    72: 'slot22',
    73: 'slot23',
    74: 'slot24',
    75: 'slot25',
    76: 'slot16',
    77: 'slot17',
    78: 'slot18',
    79: 'slot19',
    80: 'slot20',
    81: 'slot11',
    82: 'slot12',
    83: 'slot13',
    84: 'slot14',
    85: 'slot15',
    86: 'slot06',
    87: 'slot07',
    88: 'slot08',
    89: 'slot09',
    90: 'slot10',
    91: 'slot01',
    92: 'slot02',
    93: 'slot03',
    94: 'slot04',
    95: 'slot05',

    96: 'gate1',
    97: 'gate2',
    98: 'gate3',
    99: 'gate4'





}
var update_table = (data) => {
    data = JSON.parse(data)
    console.log(data)
    $('#car_details > table > tbody').empty();
    for(let child of $('[id*=path]')) {
        $(child).css({'fill': 'fff'})
    }
    let cars = Object.keys(data.cars);
    for (let i in cars) {
        var key = cars[i];
        $('#car_details > table > tbody').append(`<tr>
        <td><span class="table_car_color" style="background:${colors[i]};">${data.cars[key].id}</span></td>
        <td>${data.cars[key].last_position}</td>
        <td>${data.cars[key].in_time}</td>
        <td>${data.cars[key].out_time}</td>
        <td>${data.cars[key].parking_deadlne}</td>
        <td>${data.cars[key].leaving_deadline}</td>
        <td>${data.cars[key].park_in}</td>
        <td>${data.cars[key].park_out}</td>
        <td>${data.cars[key].arrival_tt}</td>
        <td>${data.cars[key].dearture_tt}</td>
        <td>${data.cars[key].overall_tt}</td>
        </tr>`);

        $('#'+mapping[data.cars[key].last_position]).css({'fill': colors[i]});

        // console.log(i, data.cars[key].arrival_tt)
    }

}
var update_arena = (data) => {

    data = JSON.parse(data)
    
    for (let car of parkingSlots) {
        $('#' + car).css({ 'fill': '#0f0' });
        $('#' + car + ' > rect').css({ 'fill': '' });
    }

    for (let car of data.reserved) {
        // console.log('Reserved', $('#' + mapping[car]))
        $('#' + mapping[car]).css({ 'fill': '#f00' });
        $('#' + mapping[car] + ' > rect').css({ 'fill': '' });
    }

    // for (let car of res.obstacle) {
    //     $('#' + car).css({ 'fill': '#00f' });
    //     $('#' + car + ' > rect').css({ 'fill': '' });
    //     console.log(car)
    // }

    $("#clock").text(Math.round(data.clock*100)/100 + " sec");
    
}


// $("#arena_box *").filter("[id]").each(function() { 
//     $(this).on('click', () => {
//         console.log('hover on', this.id)
//     })
// })



function showTime() {
    var date = new Date();
    var h = date.getHours(); // 0 - 23
    var m = date.getMinutes(); // 0 - 59
    var s = date.getSeconds(); // 0 - 59
    var session = "AM";

    if (h == 0) {
        h = 12;
    }

    if (h > 12) {
        h = h - 12;
        session = "PM";
    }

    h = (h < 10) ? "0" + h : h;
    m = (m < 10) ? "0" + m : m;
    s = (s < 10) ? "0" + s : s;

    var time = h + ":" + m + ":" + s + " " + session;
    document.getElementById("MyClockDisplay").innerText = time;
    document.getElementById("MyClockDisplay").textContent = time;

    setTimeout(showTime, 1000);

}

// update_arena()
// showTime();

// update_table();


setInterval(() => {
    $.get('http://localhost:8080', (data)=> {
        // res = data;
        // console.log(res)
        update_table(data);
        update_arena(data);
    })
}, 500);