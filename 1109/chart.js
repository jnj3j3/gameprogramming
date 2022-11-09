var xValues = ["Rust", "Python", "TypeScript", "Go", "JavaScript","Kotlin","C++","Java","etc"];
var yValues = [17.6, 17.59, 17.03, 16.41, 12.98,8.08,7.76,5.6,0.93];
var barColors = [
  "#FF0000",
  "#0066FF",
  "#2b5797",
  "#00CCFF",
  "#FFFF00",
  "#9900FF",
  "#000000",
  "#FF6600"
];

new Chart("languageChart", {
  type: "doughnut",
  data: {
    labels: xValues,
    datasets: [{
      backgroundColor: barColors,
      data: yValues
    }]
  },
  options: {
    title: {
      display: true,
      text: "2022 Most Wanted Programming Languages"
    }
  }
});


//second chart

var xValues = ["Tensorflow", "Flutter", "React Native", "Apache Kafka", "Torch/PyTorch","Electron","Numpy","Pandas",".NET","etc"];
var yValues = [15.33, 13.52, 13.05, 8.64, 8.57,7.93,7.49,6.7,5.38,13.39];
var barColors = [
    "#FF0000",
    "#0066FF",
    "#2b5797",
    "#00CCFF",
    "#FFFF00",
    "#9900FF",
    "#000000",
    "66FF00",
    "#FF6600"
];

new Chart("languageChart2", {
  type: "bar",
  data: {
    labels: xValues,
    datasets: [{
      backgroundColor: barColors,
      data: yValues
    }]
  },
  options: {
    legend: {display: false},
    title: {
      display: true,
      text: "2022 Most Wanted Frameworks and Libraries"
    }
  }
});
var xValues = [2014,2015,2016,2017,2018];

new Chart("languageChart3", {
  type: "line",
  data: {
    labels: xValues,
    datasets: [{ 
      data: [2926,2611,3024,3018,2992],
      borderColor: "blue",
      fill: false
    },  
    { 
      data: [1688,1521,1829,1788,1655],
      borderColor: "orange",
      fill: false
    }]
  },
  options: {
    legend: {display: false},
    title: {
        display: true,
        text: "Kyungsung Unviersity Employed vs Graduate"
      }
  }
});