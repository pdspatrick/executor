
/* Generated by Interface Builder */

#import "MacWinClass.h"

@implementation MacWindow

#ifndef OPENSTEP
- (BOOL)commandKey:(NXEvent *)theEvent
#else /* OPENSTEP */
- (BOOL)commandKey:(NSEvent *)theEvent
#endif /* OPENSTEP */
{
#ifndef OPENSTEP
    if ( [contentView performKeyEquivalent:theEvent] )
#else /* OPENSTEP */
    if ( [[self contentView] performKeyEquivalent:theEvent] )
#endif /* OPENSTEP */
        return( YES );
    else
        return( NO );
}

void ROMlib_dummywincall( void )
{
}

@end
