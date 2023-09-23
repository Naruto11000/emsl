// // const circle = {
// //     radius : 1,
// //     lacation : {
// //         x : 1,
// //         y : 1,
// //     },
// //     draw : function() {
// //         console.log('draw');
// //     }
// // };
// // circle.draw();
// //Factory Function
// function createCircle(r) {
//     return{
//         radius : r,
//         draw : function(){
//             console.log('draw');
//         }
//     }
// }
// console.log(createCircle(42));
// //constructor function
// function Circle(r) {
//     console.log('this',this) // this => keyword to create an empty object
//     this.radius = r;
//     this.draw = function(){
//         console.log('drawing');
//     }
// }

// const a = new Circle(10);
// console.log(a);
 
// function Circle(r) {
//     this.radius = r;
//     this.draw = function(){
//         console.log('ding-dong');
//     }
// }

// const Circle1 = new Function('radius', `
// this.radius = radius;
// this.draw = function(){
//     console.log('ding-dong');
// }`);

// // const circle = new Circle1(1);

// const x = Circle.call({} , 1);
// const y = Circle.apply({}, [1,2,3,4]);
// const z = new Circle(24); 

// console.log(x , y , z);

// let x = { value : 1001 };
// let y = x;
// x.value = 101;

// let number = 99;
// function increase(number) {
//     console.log(++number);
// }

// console.log(increase(number));
// console.log(number);


// let number = { value : 99 };
// function increase(number) {
//     number.value++;  
// }

// console.log(number);

function Circle(r) {
    this.radius = r;
    this.draw = function(){
        console.log('ding-dong');
    }
}

const circle = new Circle(101);

circle.location = { x: 1};

const propertyName = 'location';
 
circle[propertyName] = {x:55};