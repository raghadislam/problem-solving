/* --------- some functions that will help in Number theory problems --------- */

bool is_prime(ll num) {
    if (num == 2) return true;
    if (num < 2 || !(num % 2)) return false;

    for (ll i = 3; i * i <= num; i += 2) {
        if (!(num % i)) return false;
    }

    return true;
}

/*-----------------------------------------------*/

ll dp_fac[1000]= {1,0};
ll fac(int n) {
	if (dp_fac[n]) return dp_fac[n];
	dp_fac[n] = n * fac(n - 1);
	return dp_fac[n];
}

/*-----------------------------------------------*/

vb prime_range_sieve(ll num) {

    vb primes(num + 1, true);
    primes[0] = primes[1] = false;

    for (ll i = 2; i * i <= num; i++) {
        for (ll j = i * 2; primes[i] && j <= num; j += i) {
            primes[j] = false;
        }
    }

    return primes;
}

/*-----------------------------------------------*/

ll count_primes(ll num) {

    vb primes(num + 1);
    primes = prime_range_sieve(num);

    ll counter = 0;
    for (bool i : primes) counter += i;

    return counter;
}

/*-----------------------------------------------*/

vl get_primes(ll num) {

    vb primes_check(num + 1);
    primes_check = prime_range_sieve(num);

    vl primes;
    for (ll i = 2; i < sz(primes_check); i++) {
        if (primes_check[i]) primes.push_back(i);
    }

    return primes;
}

/*-----------------------------------------------*/

//find power primes (factorize all numbers from 1 to n) 
//and number of devisors using seive

int n=100;
vector<vector<pair<int,int>>>prime_factorizations(n+1);
vector<int> DivisorsNum(n+1,1);

void PrimePower_numOfDivisors()
{
    vector<bool> isPrime(1+n,true);
    for(int i=2; i<=n; i++)
    {
        if(isPrime[i])
        {
            for(int j =i; j<=n; j+=i)
            {
                isPrime[j]=false;
                int temp =j, cnt=0;
                while (temp%i==0)
                {
                    temp/=i; cnt++;
                }
                prime_factorizations[j].push_back({i,cnt});
                DivisorsNum[j]*=(cnt+1);
            }
        }

    }
}



/* -------------- divisors --------------- */


vl get_divisors(ll num) {

    vl divisors;

    ll i;
    for (i = 1; i * i < num; i++) {
        if (!(num % i)) {
            divisors.push_back(i);
            divisors.push_back(num / i);
        }
    }
    if((i * i) == num) divisors.push_back(i);

    return divisors;
}

ll count_divisors(ll num) {

    ll i, counter = 0;
    for (i = 1; i * i < num; i++) {
        if (!(num % i)) counter += 2;
    }
    if ((i * i) == num) counter++;

    return counter;
}



/* ----------- factorization ------------- */

vl prime_factorization(ll num) {

    vl factors;

    if (num < 2) return factors;

    while (!(num % 2)) {
        factors.push_back(2);
        num /= 2;
    }

    for (ll i = 3; i * i <= num; i += 2) {
        while (!(num % i)) {
            factors.push_back(i);
            num /= i;
        }
    }

    if (num > 1) factors.push_back(num);

    return factors;
}

/*-----------------------------------------------*/

//n^m
int pow(int n,int m){
    int sum = 1;
    for(int i = 0;i<m;i++){
        sum *= n;
    }
    return sum;
}

/*-----------------------------------------------*/

int GCD(int a, int b) {

    if (b)
        return GCD(b, a % b);
    else
        return a;
}

/*-----------------------------------------------*/

const int MAX_N = 500001; // Maximum value of n

int divisorSum[MAX_N];

// Function to precompute the divisor sum for each number
void precomputeDivisorSum() {
    for (int i = 1; i < MAX_N; ++i) {
        for (int j = i * 2; j < MAX_N; j += i) {
            divisorSum[j] += i;
        }
    }
}
/*-----------------------------------------------*/

int fastPower (int n,int m)
{
    if(m<=0) return 1;
    int res = fastPower(n,m/2);
    res = (res%MOD * res%MOD)%MOD;
    if(m&1)
    {
        res = (n%MOD * res%MOD)%MOD;
    }
    return res;
}
