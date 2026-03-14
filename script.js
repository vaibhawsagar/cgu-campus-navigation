const V = 20;

const mapLocations = [
"CGU Front Gate CV Raman Global University",
"Diploma Department CV Raman Global University",
"MBA Department CV Raman Global University",
"Cricket Ground CV Raman Global University",
"DSW Playground CV Raman Global University",
"Swimming Pool CV Raman Global University",
"Medical Dispensary CV Raman Global University",
"Boys Canteen CV Raman Global University",
"Girls Canteen CV Raman Global University",
"Basketball Court CV Raman Global University",
"RIHC Auditorium CV Raman Global University",
"Central Library CV Raman Global University",
"CSE Block CV Raman Global University",
"Mechanical Department CV Raman Global University",
"ETC Building CV Raman Global University",
"Admission Cell CV Raman Global University",
"Bosch Rexroth Center of Excellence CV Raman Global University",
"Volleyball Court CV Raman Global University",
"CSE Fountain CV Raman Global University",
"CV Raman Global University Back Gate"
];

const locations = [
"CGU Front Gate",
"Diploma Department",
"CV Raman Department of MBA",
"Cricket Ground",
"DSW Playground",
"CV Raman Swimming Pool",
"Medical Dispensary",
"Boys Canteen",
"Girls Canteen",
"CV Raman Basketball Court",
"RIHC Auditorium",
"CV Raman Central Library",
"CSE Block",
"Mechanical Department",
"ETC Building",
"Admission Cell",
"Bosch Rexroth Center of Excellence",
"CGU Volleyball Court",
"CSE Fountain",
"CV Raman Global University Backgate"
];

// Create graph matrix
let graph = Array.from({ length: V }, () => Array(V).fill(0));

function addEdge(u, v, w) {
    graph[u][v] = w;
    graph[v][u] = w;
}

// Graph edges
addEdge(0,1,82);
addEdge(0,2,92);
addEdge(0,18,500);

addEdge(1,3,100);
addEdge(1,2,120);

addEdge(3,4,270);
addEdge(3,7,350);
addEdge(3,11,400);

addEdge(4,5,110);
addEdge(4,19,350);
addEdge(4,18,200);
addEdge(4,16,130);
addEdge(4,14,300);

addEdge(5,6,100);
addEdge(5,7,130);

addEdge(6,7,230);

addEdge(7,9,200);
addEdge(7,18,400);
addEdge(7,16,270);

addEdge(2,11,350);
addEdge(2,10,180);

addEdge(11,15,200);
addEdge(11,19,100);

addEdge(15,14,100);
addEdge(15,12,160);

addEdge(14,13,150);

addEdge(13,12,100);
addEdge(13,18,180);

addEdge(12,8,300);
addEdge(12,18,70);
addEdge(12,19,270);
addEdge(12,17,280);

addEdge(18,17,210);
addEdge(18,8,300);
addEdge(18,16,110);

addEdge(8,17,94);

addEdge(17,9,53);





// Dijkstra Algorithm
function dijkstra(src, dest) {

    let dist = new Array(V).fill(Infinity);
    let visited = new Array(V).fill(false);
    let parent = new Array(V).fill(-1);

    dist[src] = 0;

    for (let i = 0; i < V - 1; i++) {

        let min = Infinity;
        let u = -1;

        for (let j = 0; j < V; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u === -1) break;

        visited[u] = true;

        for (let v = 0; v < V; v++) {

            if (!visited[v] && graph[u][v] !== 0 &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Reconstruct path
    let path = [];
    let crawl = dest;

    while (crawl !== -1) {
        path.push(locations[crawl]);
        crawl = parent[crawl];
    }

    path.reverse();

    return {
        distance: dist[dest],
        path: path
    };
}


// Button function
function findPath() {

    let source = parseInt(document.getElementById("source").value);
    let destination = parseInt(document.getElementById("destination").value);

    let result = dijkstra(source, destination);

    // let output = "<h3>Shortest Route</h3>";
    // output += "<b>Distance:</b> " + result.distance + " meters<br><br>";

    // output += "<b>Path:</b><br>";

    // for (let i = 0; i < result.path.length; i++) {
    //     output += result.path[i];

    //     if (i < result.path.length - 1) {
    //         output += " ↓ <br>";
    //     }
    // }

    // document.getElementById("result").innerHTML = output;

    let output = `
<h3>Shortest Route</h3>
<p><b>Distance:</b> ${result.distance} meters</p>
<p><b>Path:</b></p>
`;

result.path.forEach((place,i)=>{
output += place;
if(i < result.path.length-1)
output += "<br>⬇<br>";
});

document.getElementById("result").innerHTML = output;

    let map = document.getElementById("campusMap");

let destinationPlace = mapLocations[destination];

map.src =
"https://maps.google.com/maps?q=" +
encodeURIComponent(destinationPlace) +
"&t=&z=17&ie=UTF8&iwloc=&output=embed";
}

