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
        var a = res[i].split(" ");
        i++;
        var dict =[];
         for(var j=0;j<n;j++){
            if(dict[parseInt(a[j],10)]!==undefined)
                dict[parseInt(a[j],10)]++;
            else dict[parseInt(a[j],10)]=1;
        }
        var ans=1e12,sum=0;
        for(var key in dict){
            sum+=key*dict[key];
            ans=Math.min(ans,key*dict[key]);
        }
        console.log(sum-ans);
    }
}
