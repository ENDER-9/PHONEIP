const clientModule = require('../build/Release/clientModule.node');

function startRequest() {
  let firstName = 'Julian'
  let lastName = 'Jaksch'
  let birthday = '06.02.2004'
  let phoneNumber = '0152/32040882'
  let street = 'Wiesenstraße 13'
  let city = 'Roßtal'
  let postcode = 90574
  let answer = clientModule.sendAddPersonServerJs(
      firstName, lastName, birthday, phoneNumber, street, city, postcode);

  console.log(answer);
}
