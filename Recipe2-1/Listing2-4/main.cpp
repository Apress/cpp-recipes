int main()
{
    int number{ 0 };
    char another{ static_cast<char>(512) };
    
    double bigNumber{ 1.0 };
    float littleNumber{ static_cast<float>(bigNumber) }; 
 
    return 0;
}
