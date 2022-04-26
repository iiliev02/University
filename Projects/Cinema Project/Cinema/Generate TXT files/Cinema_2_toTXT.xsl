<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" encoding="UTF-8" indent="yes"/>

    <xsl:variable name="separator" select="' | '"/>
    <xsl:variable name="new_row" select="'&#13;'"/>

    <xsl:template name="contacts" match="/">
        <xsl:text>Movies</xsl:text>
        <xsl:value-of select="$new_row"/>
        <xsl:value-of select="$new_row"/>
        <xsl:apply-templates select="/cinema/movies"/>
    </xsl:template>

    <xsl:template match="/cinema/movies">
        <xsl:for-each select = "movie">
            <xsl:text>Name: </xsl:text><xsl:value-of select="movieName"/><xsl:value-of select="$new_row"/>
            <xsl:text>Actors: </xsl:text><xsl:value-of select="normalize-space(actors)"/><xsl:value-of select="$new_row"/>
            <xsl:text>Description: </xsl:text><xsl:value-of select="normalize-space(movieDescription)"/><xsl:value-of select="$new_row"/>
            <xsl:value-of select="$new_row"/>
        </xsl:for-each>
    </xsl:template>

</xsl:transform>