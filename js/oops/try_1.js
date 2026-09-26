class myClass {
  name;
  age;
  bussiness;
  education;

  constructor(name, age, bussiness, education) {
    this.name = name;
    this.age = age;
    this.bussiness = bussiness;
    this.education = education;
  }

  func(val1, val2) {
    console.log(val1 * val2);
  }
}

const newClass1 = new myClass('M Haris', 21, 'web development', 'BS');
const newClass2 = new myClass('Amad', 22, 'App development', 'FCS');
const func = new myClass();
console.log(func);
console.log(newClass1);
console.log(newClass2);
