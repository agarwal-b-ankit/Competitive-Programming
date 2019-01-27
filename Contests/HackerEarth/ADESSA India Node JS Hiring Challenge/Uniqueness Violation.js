process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";

process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});

process.stdin.on("end", function () {
   main(stdin_input);
});

function main(input) {
    //process.stdout.write("Hi, " + input + ".\n");       // Writing output to STDOUT
    var res=input.split("\n");
    var t=parseInt(res[0],10);
    var i=1;
    while(t-->0){
        var n=parseInt(res[i],10);
        i++;
        var u = res[i].split(" ");
        i++;
        var a = res[i].split(" ");
        i++;
        var ans=0;
         for(var j=0;j<n;){
             var k,max=parseInt(a[j],10);
            for(k=j+1;k<n;k++){
                if(u[k]===u[j])
                    max=Math.max(max,parseInt(a[k],10));
                else break;
            }
            ans+=max;
            j=k;
        }
        console.log(ans);
    }
}
