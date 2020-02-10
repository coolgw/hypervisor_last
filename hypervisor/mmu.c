#define MAX_PAGE_PDE    8
unsigned int page_directory[MAX_PAGE_PDE] __attribute__((aligned(4096)));
unsigned int page_tables[MAX_PAGE_PDE][1024] __attribute__((aligned(4096)));

extern void loadPageDirectory(unsigned int*);
extern void enablePaging();



void init_page_directory() {
    int i;
    int j;
    for(i = 0; i < MAX_PAGE_PDE; i++)
    {
        // This sets the following flags to the pages:
        //   Supervisor: Only kernel-mode can access them
        //   Write Enabled: It can be both read from and written to
        //   Not Present: The page table is not present
        page_directory[i] = 0x00000002;
    }

    for (j=0; j<8; j++) {
        for(i = 0; i < 1024; i++)
        {
            // As the address is page aligned, it will always leave 12 bits zeroed.
            // Those bits are used by the attributes ;)
            page_tables[j][i] = (i * 0x1000) | 3; // attributes: supervisor level, read/write, present.
        }
        page_directory[j]=(unsigned int)page_tables[j] | 3;
    }


    loadPageDirectory(page_directory);
    enablePaging();

}

