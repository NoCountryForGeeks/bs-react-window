open ReasonWindow;

[@react.component]
let make = () => {
    <div>
        <FixedSizeList
            className={"fixed"}
            direction={List.Ltr}
            height={200}
            itemCount={1000}
            itemSize={50}
            layout={List.Vertical}
            onItemsRendered={Js.log}
            onScroll={Js.log}
            useIsScrolling={true}
            style={ReactDOMRe.Style.make(~background="red", ())}
            overscanCount={10}
            width={200}
        >
            {cellProps => <Cell cellProps/>}
        </FixedSizeList>
        <VariableSizeList
            className={"variable"}
            direction={List.Ltr}
            estimatedItemSize={100}
            height={200}
            itemCount={100}
            itemSize={index => index + 50}
            layout={List.Vertical}
            onItemsRendered={Js.log}
            onScroll={Js.log}
            useIsScrolling={true}
            style={ReactDOMRe.Style.make(~background="green", ())}
            overscanCount={10}
            width={200}
        >
            {cellProps => <Cell cellProps/>}
        </VariableSizeList>
        <FixedSizeGrid
            className={"fixedGrid"}
            columnCount={1000}
            columnWidth={100}
            direction={Grid.Ltr}
            height={300}
            onItemsRendered={Js.log}
            onScroll={Js.log}
            overscanColumnCount={5}
            overscanRowCount={5}
            rowCount={1000}
            rowHeight={50}
            style={ReactDOMRe.Style.make(~background="blue", ())}
            useIsScrolling={true}
            width={300}
        >
            {gridCellProps => <GridCell gridCellProps />}
        </FixedSizeGrid>
        <VariableSizeGrid
            className={"variableGrid"}
            columnCount={1000}
            columnWidth={index => index + 50}
            direction={Grid.Ltr}
            estimatedColumnWidth={20}
            estimatedRowHeight={20}
            height={300}
            onItemsRendered={Js.log}
            onScroll={Js.log}
            overscanColumnCount={5}
            overscanRowCount={5}
            rowCount={1000}
            rowHeight={index => index + 50}
            style={ReactDOMRe.Style.make(~background="yellow", ())}
            useIsScrolling={true}
            width={300}
        >
            {gridCellProps => <GridCell gridCellProps />}
        </VariableSizeGrid>
    </div>
    
};
