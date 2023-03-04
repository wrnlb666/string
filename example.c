#include "str.h"

// compare function for str_sort, from longest to shortest
int compar( const void* arg1, const void* arg2 )
{
    str_t str1 = *(string_t**) arg1;
    str_t str2 = *(string_t**) arg2;
    return str_strlen(str2) - str_strlen(str1);
}

int main( void )
{
    str_t str = str_new_strings( "Hello World", "  ", "😊😂😃😆🤔", "  ", "你好世界", "  ", "こんにちは世界", "  ", "헬로 월드", NULL );

    str_t* arr = str_split( str, "  " );
    printf( "string slices: \n" );
    for ( size_t i = 0; arr[i] != NULL; i++ )
    {
        printf( "%zu, %s\n", str_strlen( arr[i] ), str_cstr(arr[i]) );
    }
    str_sort( arr, 0, "c", &compar );
    printf( "sorted: \n" );
    for ( size_t i = 0; arr[i] != NULL; i++ )
    {
        printf( "%zu, %s\n", str_strlen( arr[i] ), str_cstr(arr[i]) );
    }
    // not necessary if define USE_GC
    str_free_arr( arr );

    str_t str2 = str_replace( str, "  ", " " );
    str_t str3 = str_substr( str2, 3, 8 );
    str_t str4 = str_append_cstrs( str2, " ", "123", "456", NULL );

    printf( "info for changes:\n" );
    printf( "%zu, %s\n", str_strlen(str), str_cstr(str) );
    printf( "%zu, %s\n", str_strlen(str2), str_cstr(str2) );
    printf( "%zu, %s\n", str_strlen(str3), str_cstr(str3) );
    printf( "%zu, %s\n", str_strlen(str4), str_cstr(str4) );

    wchar_t* str5 = str_wstr( str );
    wprintf( L"%ls", str5 );
    // not necessary if define USE_GC
    str_free( str5 );

    // not necessary if define USE_GC
    str_frees( str, str2, str3, str4, NULL );

    return 0;
}